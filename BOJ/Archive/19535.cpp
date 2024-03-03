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
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> g[3*MAX];

ll dfs(int x, int p) {
    ll ret = 0, degsum = 0;
    for(auto i : g[x]) {
        if(i == p) continue;
        ret += dfs(i, x);
        degsum += g[i].size() - 1;
    }
    return ret + degsum * (g[x].size() - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }
    ll cntd = 0, cntg = 0;

    cntd = dfs(1, 0);

    for(int i = 1; i <= n; i++) {
        ll deg = g[i].size();
        cntg += deg * (deg - 1) * (deg - 2) / 6;
    }

    if(cntd > 3 * cntg) cout << "D" << endl;
    if(cntd == 3 * cntg) cout << "DUDUDUNGA" << endl;
    if(cntd < 3 * cntg) cout << "G" << endl;

    return 0;
}