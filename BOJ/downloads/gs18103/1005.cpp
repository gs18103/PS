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

int dp[1010], d[1010], ind[1010];
vector <int> g[1010];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for(int i = 1; i <= n; i++) {
        dp[i] = 0, g[i].clear();
        ind[i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        ind[v]++;
    }
    queue <int> q;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) q.em(i);
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        dp[x] += d[x];
        for(auto i : g[x]) {
            ind[i]--;
            dp[i] = max(dp[i], dp[x]);
            if(ind[i] == 0) q.em(i);
        }
    }
    int w;
    cin >> w;
    cout << dp[w] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}