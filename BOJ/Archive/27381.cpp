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

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

vector <int> g[MAX], v[MAX];
int deg[MAX];

void dfs(int x, int pa, int t) {
    v[t].eb(x);
    for(int i : g[x]) {
        if(i == pa) continue;
        dfs(i, x, t + 1);
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        v[i].clear();
        deg[i] = 0;
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
        deg[u]++, deg[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1) {
            dfs(i, 0, 1);
            break;
        }
    }
    if(v[4].empty()) {
        cout << "-1\n";
        return;
    }
    for(int i = 2; i <= n; i += 2) {
        for(int j : v[i]) cout << j << ' ';
    }
    for(int i = 1; i <= n; i += 2) {
        for(int j : v[i]) cout << j << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}