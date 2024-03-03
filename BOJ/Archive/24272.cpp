#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

struct SegmentTree {
    struct Node {
        int mn = 0, c = 1;
        Node(int mn, int c) : mn(mn), c(c) {}
        Node(){}
        Node operator + (const Node &X) {
            if(mn < X.mn) return Node(mn, c);
            else if(mn > X.mn) return X;
            else return Node(mn, c+X.c);
        }
    };
    vector <Node> tree;
    vector <int> lazy;
    int sz;
    void Init(int n) {
        tree.resize(4*n+10);
        lazy.resize(4*n+10);
        sz = n;
        init(1, 1, n);
    }
    void init(int node, int s, int e) {
        if(s == e) return;
        int m = s + e >> 1;
        init(node<<1, s, m);
        init(node<<1|1, m+1, e);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
    void update_lazy(int node, int s, int e) {
        tree[node].mn += lazy[node];
        if(s != e) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }
    
    void update(int l, int r, int val) {
        update(1, 1, sz, l, r, val);
    }

    void update(int node, int s, int e, int l, int r, int val) {
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            lazy[node] += val;
            update_lazy(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update(node<<1, s, m, l, r, val);
        update(node<<1|1, m+1, e, l, r, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
};

int in[MAX], out[MAX], num;
pair <pii, int> E[MAX];
vector <int> g[MAX];

void dfs(int x, int pa) {
    in[x] = ++num;
    for(auto i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
    }
    out[x] = num;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    map <pii, int> mp;
    for(int i = 1; i < n; i++) {
        int u, v;
        string s;
        cin >> u >> s >> v;
        if(u > v) swap(u, v);
        mp[{u, v}] = i;
        g[u].eb(v), g[v].eb(u);
        E[i].fi = {u, v};
        if(s == "->") E[i].se = 1;
        if(s == "<-") E[i].se = -1;
    }
    dfs(1, 0);

    SegmentTree ST;
    ST.Init(n);

    for(int i = 1; i < n; i++) {
        int u = E[i].fi.fi, v = E[i].fi.se, f = E[i].se;
        if(in[u] > in[v]) swap(u, v), f = -f;
        if(f > 0) ST.update(in[v], out[v], 1);
        if(f < 0) ST.update(1, in[v]-1, 1), ST.update(out[v]+1, n, 1);
    }

    int q;
    cin >> q;
    while(q--) {
        int u, v; string s;
        cin >> u >> s >> v;
        int x;
        if(s == "->") x = 1;
        if(s == "<-") x = -1;
        if(s == "--") x = 0;
        if(u > v) swap(u, v), x = -x;

        int i = mp[{u, v}];
        int f = E[i].se;
        if(in[u] > in[v]) swap(u, v), f = -f;
        if(f > 0) ST.update(in[v], out[v], -1);
        if(f < 0) ST.update(1, in[v]-1, -1), ST.update(out[v]+1, n, -1);

        E[i].se = x;
        u = E[i].fi.fi, v = E[i].fi.se, f = E[i].se;
        if(in[u] > in[v]) swap(u, v), f = -f;
        if(f > 0) ST.update(in[v], out[v], 1);
        if(f < 0) ST.update(1, in[v]-1, 1), ST.update(out[v]+1, n, 1);

        ST.update_lazy(1, 1, n);
        int mn = ST.tree[1].mn, c = ST.tree[1].c;
        if(mn > 0) cout << "0\n";
        else cout << c << '\n';
    }
}