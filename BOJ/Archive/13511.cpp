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
const ll LINF = (ll)1e63;

ll d[20][MAX];
int p[20][MAX], dep[MAX];

vector <pair <int, ll> > g[MAX];

void dfs(int x, int pa) {
    p[0][x] = pa;
    dep[x] = dep[pa] + 1;
    for(int i = 1; i < 20; i++) {
        p[i][x] = p[i-1][p[i-1][x]];
        d[i][x] = d[i-1][x] + d[i-1][p[i-1][x]];
    }
    for(auto i : g[x]) {
        if(i.fi == pa) continue;
        d[0][i.fi] = i.se;
        dfs(i.fi, x);
    }
}

ll query_dist(int u, int v) {
    ll ans = 0;
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 19; i >= 0; i--) {
        if(dep[v] - (1 << i) >= dep[u]) {
            ans += d[i][v];
            v = p[i][v];
        }
    }
    if(u == v) return ans;
    for(int i = 19; i >= 0; i--) {
        if(p[i][v] != p[i][u]) {
            ans += d[i][v] + d[i][u];
            u = p[i][u];
            v = p[i][v];
        }
    }
    ans += d[0][v] + d[0][u];
    return ans;
}

int query_kth(int x, int y, int k) {
    int u = x, v = y;
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 19; i >= 0; i--) {
        if(dep[v] - (1 << i) >= dep[u]) {
            v = p[i][v];
        }
    }
    for(int i = 19; i >= 0; i--) {
        if(p[i][v] != p[i][u]) {
            u = p[i][u];
            v = p[i][v];
        }
    }
    if(u != v) u = p[0][u];
    int up = k - 1;
    if(dep[x] - dep[u] + 1 < k) {
        up = dep[x] + dep[y] - 2 * dep[u] + 1 - k;
        swap(x, y);
    }
    for(int i = 19; i >= 0; i--) {
        if(up >= (1 << i)) {
            up -= (1 << i);
            x = p[i][x];
        }
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].eb(v, w), g[v].eb(u, w);
    }

    dfs(1, 0);

    int q;
    cin >> q;
    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1) {
            cout << query_dist(u, v) << '\n';
        }
        if(t == 2) {
            int k;
            cin >> k;
            cout << query_kth(u, v, k) << '\n';
        }
    }
}