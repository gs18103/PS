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

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> g[MAX];
int dep[MAX], p[20][MAX];

void dfs(int x, int pa) {
    p[0][x] = pa;
    dep[x] = dep[pa] + 1;
    for(int i = 1; i < 20; i++) {
        p[i][x] = p[i-1][p[i-1][x]];
    }
    for(auto i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
    }
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 19; i >= 0; i--) {
        if(dep[u] >= dep[v] + (1 << i)) u = p[i][u];
    }
    if(u == v) return u;
    for(int i = 19; i >= 0; i--) {
        if(p[i][u] != p[i][v]) u = p[i][u], v = p[i][v];
    }
    return p[0][u];
}

int dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)] + 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    dfs(1, 0);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i * 2; j <= n; j += i) {
            ans += dist(i, j);
        }
    }
    cout << ans;
}