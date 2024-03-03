#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

vector <pii> g[MAX];

int p[20][MAX], mn[20][MAX], mx[20][MAX], dep[MAX];

void dfs(int x, int pa) {
    p[0][x] = pa;
    dep[x] = dep[pa] + 1;
    for(int i = 1; i < 20; i++) {
        p[i][x] = p[i-1][p[i-1][x]];
        mn[i][x] = min(mn[i-1][x], mn[i-1][p[i-1][x]]);
        mx[i][x] = max(mx[i-1][x], mx[i-1][p[i-1][x]]);
    }

    for(auto i : g[x]) {
        if(i.fi == pa) continue;
        mn[0][i.fi] = mx[0][i.fi] = i.se;
        dfs(i.fi, x);
    }
}

pii lca(int u, int v) {
    pii ret = {INF, 0};
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 19; i >= 0; i--) {
        if(dep[u] - dep[v] >= (1 << i)) {
            ret.fi = min(ret.fi, mn[i][u]);
            ret.se = max(ret.se, mx[i][u]);
            u = p[i][u];
        }
    }
    if(u == v) return ret;
    for(int i = 19; i >= 0; i--) {
        if(p[i][u] != p[i][v]) {
            ret.fi = min(ret.fi, mn[i][u]);
            ret.se = max(ret.se, mx[i][u]);
            ret.fi = min(ret.fi, mn[i][v]);
            ret.se = max(ret.se, mx[i][v]);
            u = p[i][u];
            v = p[i][v];
        }
    }
    ret.fi = min(ret.fi, mn[0][u]);
    ret.se = max(ret.se, mx[0][u]);
    ret.fi = min(ret.fi, mn[0][v]);
    ret.se = max(ret.se, mx[0][v]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    for(int i = 0; i < 20; i++) {
        mn[i][0] = INF;
    }
    mn[0][1] = INF;
    dfs(1, 0);

    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        pii ans = lca(u, v);
        cout << ans.fi << ' ' << ans.se << '\n';
    }
}