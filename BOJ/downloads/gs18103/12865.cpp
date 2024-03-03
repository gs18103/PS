#include <bits/stdc++.h>

using namespace std;

int dp[101][101010];
int v[101], w[101];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
}
