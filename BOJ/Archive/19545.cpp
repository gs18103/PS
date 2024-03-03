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

const int MAX = 3030;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

ll dp[2][MAX][MAX], u[MAX], d[MAX];
int n, m;
ll l;

ll dist(int i, int j) {
    return l * l + (u[i] - d[j]) * (u[i] - d[j]);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> l;
    for(int i = 1; i <= n; i++) {
        cin >> u[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> d[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[0][i][j] = dp[1][i][j] = LINF;
        }
    }
    dp[0][1][1] = dp[1][1][1] = dist(1, 1) * (n + m - 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j > 1) {
                dp[0][i][j] = min({
                    dp[0][i][j-1] + dist(i, j - 1) * ((n + m - 1) - (i + j - 2) * (n + m - i - j + 2)),
                    dp[1][i][j-1]
                });
                dp[0][i][j] += dist(i, j) * (i + j - 1) * (n + m - i - j + 1);
            }
            if(i > 1) {
                dp[1][i][j] = min({
                    dp[1][i-1][j] + dist(i - 1, j) * ((n + m - 1) - (i + j - 2) * (n + m - i - j + 2)),
                    dp[0][i-1][j]
                });
                dp[1][i][j] += dist(i, j) * (i + j - 1) * (n + m - i - j + 1);                
            }
            //cout << i << ' ' << j << ' ' << dp[0][i][j] << ' ' << dp[1][i][j] << endl;
        }
    }
    cout << min(dp[0][n][m], dp[1][n][m]) << endl;
}