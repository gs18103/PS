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

const int MAX = 101010;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

vector <pii> g[3*MAX];
int dep[3*MAX], p[20][3*MAX];
int d[20][3*MAX], tree[12*MAX];

void dfs(int x, int pa) {
    for(int i = 1; i < 20; i++) {
        p[i][x] = p[i-1][p[i-1][x]];
        d[i][x] = max(d[i-1][p[i-1][x]], d[i-1][x]);
    }
    for(auto i : g[x]) {
        if(i.fi == pa) continue;
        dep[i.fi] = dep[x] + 1;
        p[0][i.fi] = x;
        d[0][i.fi] = i.se;
        dfs(i.fi, x);
    }
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    int ret = 0;
    for(int i = 19; i >= 0; i--) {
        if((1 << i) <= dep[u] - dep[v]) {
            ret = max(d[i][u], ret);
            u = p[i][u];
        }
    }
    if(u == v) return ret;
    for(int i = 19; i >= 0; i--) {
        if(p[i][u] != p[i][v]) {
            ret = max(ret, d[i][u]);
            ret = max(ret, d[i][v]);
            u = p[i][u];
            v = p[i][v];
        }
    }
    return max(ret, max(d[0][u], d[0][v]));
}

void init(int node, int s, int e) {
    if(s == e) {
        tree[node] = lca(s, s + 1);
        return;
    }
    int m = (s + e) >> 1;
    init(node<<1, s, m), init(node<<1|1, m+1, e);
    tree[node] = max(tree[node<<1], tree[node<<1|1]);
}

int cal(int node, int s, int e, int l, int r) {
    if(s > r || e < l) return -LINF;
    if(s >= l && e <= r) return tree[node];
    int m = (s + e) >> 1;
    return max(cal(node<<1, s, m, l, r), cal(node<<1|1, m+1, e, l, r));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w), g[v].eb(u, w);
    }
    dfs(1, 0);
    if(n > 1) init(1, 1, n-1);
    while(q--) {
        int s, e;
        cin >> s >> e;
        if(s == e) cout << "0\n";
        else cout << cal(1, 1, n-1, s, e-1) << '\n';
    }
}