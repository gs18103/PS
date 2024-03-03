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

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

ll dp[1010][101][3];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++) dp[1][i][0] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2]) % mod;
            for(int k = 1; k < j; k++) {
                dp[i][j][1] += dp[i-1][k][2] + dp[i-1][k][1] + dp[i-1][k][0];
                dp[i][j][1] %= mod;
            }
            for(int k = j + 1; k <= m; k++) {
                dp[i][j][2] += dp[i-1][k][2] + dp[i-1][k][0];
                dp[i][j][2] %= mod;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        ans += dp[n][i][0] + dp[n][i][1] + dp[n][i][2];
        ans %= mod;
    }
    cout << ans;
}