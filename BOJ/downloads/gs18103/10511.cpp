#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int INF = 1e9;
const ll LINF = 1e18;

struct PST {
    struct Node {
        int l, r;
        ll val;
        Node(int _l, int _r, ll _val) : l(_l), r(_r), val(_val) {}
    };
    vector <Node> tree;
    vector <int> root;
    int sz;
    PST(int n) : sz(n) {
        root.eb(tree.size());
        tree.eb(0, 0, 0);
    }

    void update(int k, int val) {
        root.eb(tree.size());
        tree.eb(0, 0, 0);
        update(root.back(), root[root.size()-2], 0, sz-1, k, val);
        return;
    }
    void update(int cnd, int pnd, int s, int e, int k, int val) {
        tree[cnd].val = tree[pnd].val + val;
        if(s == e) return;
        int m = (s + e) / 2;
        if(k <= m) {
            tree[cnd].l = tree.size();
            tree[cnd].r = tree[pnd].r;
            tree.eb(0, 0, 0);
            update(tree[cnd].l, tree[pnd].l, s, m, k, val);
        }
        else {
            tree[cnd].l = tree[pnd].l;
            tree[cnd].r = tree.size();
            tree.eb(0, 0, 0);
            update(tree[cnd].r, tree[pnd].r, m+1, e, k, val);
        }
        return;
    }

    int cal(int L, int R, int r) {
        return cal(root[L-1], root[R], 0, sz-1, r);
    }
    ll cal(int pnd, int cnd, int s, int e, int r) {
        if(s > r) return 0;
        if(e <= r) return tree[cnd].val - tree[pnd].val;
        int m = (s + e) / 2;
        return cal(tree[pnd].l, tree[cnd].l, s, m, r) + cal(tree[pnd].r, tree[cnd].r, m+1, e, r);
    }
};

struct DSU {
    vector <int> p, sz;
    DSU(int n) {
        p.resize(n+1);
        sz.resize(n+1);
        for(int i = 1; i <= n; i++) {
            p[i] = i; sz[i] = 1;
        }
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        p[y] = x;
        return true;
    }
};

struct Edge {
    int u = 0, v = 0, w = 0;
};

pii dfs(int x, int pa, int tar, vector <set <pii>> &g, vector <Edge> &E) {
    for(pii i : g[x]) {
        if(i.fi == pa) continue;
        if(i.fi == tar) return pii(i.se, 1);
        pii val = dfs(i.fi, x, tar, g, E);
        if(val.se) {
            if(E[val.fi].w > E[i.se].w) val.fi = i.se;
            return val;
        }
    }
    return pii(0, 0);
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector <Edge> E(m+1);
    for(int i = 1; i <= m; i++) {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    sort(next(E.begin()), E.end(), [](Edge &a, Edge &b) { return a.w < b.w; });

    PST T(m+1);
    DSU S(n);
    vector <set <pii>> g(n+1);
    vector <int> pre(m+1);

    for(int i = 1; i <= m; i++) {
        if(!S.uni(E[i].u, E[i].v)) {
            pre[i] = dfs(E[i].u, 0, E[i].v, g, E).fi;
            g[E[pre[i]].u].erase(pii(E[pre[i]].v, pre[i]));
            g[E[pre[i]].v].erase(pii(E[pre[i]].u, pre[i]));
        }
        g[E[i].u].em(E[i].v, i);
        g[E[i].v].em(E[i].u, i);
        T.update(pre[i], E[i].w);
    }

    int q;
    ll c = 0;
    cin >> q;
    while(q--) {
        ll tl, tr;
        cin >> tl >> tr;
        int l = tl - c, r = tr - c;
        int L, R;
        int lb = 1, ub = m;
        while(lb < ub) {
            int m = (lb + ub) / 2;
            if(E[m].w >= l) ub = m;
            else lb = m + 1;
        }
        L = lb;
        lb = 1, ub = m;
        while(lb < ub) {
            int m = (lb + ub + 1) / 2;
            if(E[m].w <= r) lb = m;
            else ub = m - 1;
        }
        R = lb;
        c = T.cal(L, R, L - 1);
        cout << c << '\n';
    }

    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}