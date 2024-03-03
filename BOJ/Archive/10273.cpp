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
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> v(n+1), dp(n+1), ind(n+1), pre(n+1);
    vector <vector <pii> > g(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        dp[i] = -2*INF;
    }
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w);
        ind[v]++;
    }
    queue <int> q;
    q.em(1);
    dp[1] = v[1];
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto i : g[x]) {
            ind[i.fi]--;
            if(dp[i.fi] < dp[x] + v[i.fi] - i.se) {
                dp[i.fi] = dp[x] + v[i.fi] - i.se;
                pre[i.fi] = x;
            }
            if(ind[i.fi] == 0) q.em(i.fi);
        }
    }
    int ans = -INF, x = -1;
    for(int i = 1; i <= n; i++) {
        if(dp[i] > ans) {
            ans = dp[i];
            x = i;
        }
    }
    vector <int> path;
    while(x != 1) {
        path.eb(x);
        x = pre[x];
    }
    path.eb(1);
    cout << ans << ' ' << path.size() << '\n';
    while(!path.empty()) {
        cout << path.back() << ' ';
        path.pop_back();
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) solve();
}