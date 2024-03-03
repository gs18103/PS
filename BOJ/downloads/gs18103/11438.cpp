#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int INF = 1 << 30;
const ll LINF = 1LL << 62;
const int MAX = 101010;

int p[20][MAX], dep[MAX];
vector <int> g[MAX];

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
        if((dep[u] - dep[v]) >= (1 << i)) {
            u = p[i][u];
        }
    }
    if(u == v) return u;
    for(int i = 19; i >= 0; i--) {
        if(p[i][u] != p[i][v]) {
            u = p[i][u], v = p[i][v];
        }
    }
    return p[0][u];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    dfs(1, 0);

    int m;
    cin >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}