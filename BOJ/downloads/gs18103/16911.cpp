#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector <int> p, rank;
    vector <pair <int, int>> past;
    DSU(int n) {
        p.resize(n+1);
        rank.resize(n+1);
        for(int i = 0; i <= n; i++) {
            p[i] = i;
        }
    }
    
    int find(int x) {
        return x == p[x] ? x : find(p[x]);
    }
    
    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y);
        p[y] = x;
        past.emplace_back(y, 0);
        if(rank[x] == rank[y]) {
            rank[x]++;
            past[past.size()-1].second = x;
        }
        return true;
    }
    
    void rollback() {
        int y = past.back().first, x = past.back().second;
        p[y] = y;
        if(x) rank[x]--;
        past.pop_back();
    }
};

struct Query {
    int t, u, v;
    bool ans;
};

struct SEG {
    vector <vector <int>> tree;
    int sz;
    SEG(int n) : sz(n) {
        tree.resize(4*n+10);
    }
    
    void update(int l, int r, int val) {
        update(1, 1, sz, l, r, val);
    }
    void update(int node, int s, int e, int l, int r, int val) {
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            tree[node].push_back(val);
            return;
        }
        int m = (s + e) / 2;
        update(node<<1, s, m, l, r, val);
        update(node<<1|1, m+1, e, l, r, val);
    }
};

void dnc(int node, int s, int e, DSU &S, vector <Query> &Q, SEG &ST) {
    
    int cnt = 0;
    for(int i : ST.tree[node]) {
        if(S.uni(Q[i].u, Q[i].v)) cnt++;
    }
    
    if(s == e) {
        if(Q[s].t == 3) Q[s].ans = (S.find(Q[s].u) == S.find(Q[s].v));
    }
    else {
        int m = (s + e) / 2;
        dnc(node<<1, s, m, S, Q, ST);
        dnc(node<<1|1, m+1, e, S, Q, ST);
    }
    
    for(int i = 0; i < cnt; i++) {
        S.rollback();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector <Query> Q(q+1);
    map <pair <int, int>, int> E;
    SEG ST(q);
    DSU S(n);
    
    for(int i = 1; i <= q; i++) {
        cin >> Q[i].t >> Q[i].u >> Q[i].v;
        if(Q[i].u > Q[i].v) swap(Q[i].u, Q[i].v);
        if(Q[i].t == 1) {
            E[make_pair(Q[i].u, Q[i].v)] = i;
        }
        if(Q[i].t == 2) {
            ST.update(E[make_pair(Q[i].u, Q[i].v)], i, i);
            E.erase(make_pair(Q[i].u, Q[i].v));
        }
    }
    for(auto &x : E) {
        ST.update(x.second, q, x.second);
    }
    
    dnc(1, 1, q, S, Q, ST);
    for(int i = 1; i <= q; i++) {
        if(Q[i].t == 3) cout << Q[i].ans << '\n';
    }
}