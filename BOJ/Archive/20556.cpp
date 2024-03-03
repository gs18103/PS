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

const int MAX = 303030;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> g[MAX];
vector <pii> Q[MAX];
int sz[MAX], n, q;
ll ans[MAX];

struct SEG {
    vector <pll> tree;
    int sz;
    void Init(int n) {
        sz = n;
        tree.resize(4*n+10);
    }
    void update(int node, int s, int e, int k, int val) {
        if(s == e) {
            tree[node].fi += val;
            tree[node].se += val * s;
            return;
        }
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, val);
        else update(node<<1|1, m+1, e, k, val);
        tree[node].fi = tree[node<<1].fi + tree[node<<1|1].fi;
        tree[node].se = tree[node<<1].se + tree[node<<1|1].se;
    }
    void update(int k, ll val) {
        update(1, 1, sz, k, val);
    }
    ll cal(int node, int s, int e, int x) {
        if(s == e) return 2 * (ll)(tree[node].fi - x) * s + (ll)x * s;
        int cnt = tree[node<<1|1].fi, m = s + e >> 1;
        if(cnt >= x) return 2 * tree[node<<1].se + cal(node<<1|1, m+1, e, x);
        else return cal(node<<1, s, m, x - cnt) + tree[node<<1|1].se;
    }
    ll cal(int x) {
        if(x == 0) return tree[1].se * 2;
        return cal(1, 1, sz, x);
    }
} ST;

void dfs(int x, int pa) {
    sz[x] = 1;
    for(auto i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
        sz[x] += sz[i];
    }
}

void ndfs(int x, int pa) {
    for(auto i : Q[x]) {
        ans[i.se] = ST.cal(i.fi);
    }
    for(auto i : g[x]) {
        if(i == pa) continue;
        int tval = sz[i];
        ST.update(tval, -1);
        sz[i] = n;
        sz[x] -= tval;
        ST.update(sz[x], 1);
        ndfs(i, x);
        ST.update(sz[x], -1);
        sz[x] = n;
        sz[i] = tval;
        ST.update(tval, 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    for(int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        Q[u].eb(v, i);
    }

    dfs(1, 0);
    ST.Init(n);
    for(int i = 2; i <= n; i++) {
        ST.update(sz[i], 1);
    }
    ndfs(1, 0);
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}