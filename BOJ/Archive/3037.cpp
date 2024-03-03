#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int dp[1010][10101], dpsum[1010][10101];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, c;
    cin >> n >> c;
    dp[1][0] = 1;
    for(int i = 0; i <= c; i++) dpsum[1][i] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= c; j++) {
            if(j <= i-1) dp[i][j] = dpsum[i-1][j];
            else dp[i][j] = (dpsum[i-1][j] - dpsum[i-1][j-i] + mod) % mod;
            if(j != 0) dpsum[i][j] = (dpsum[i][j-1] + dp[i][j]) % mod;
            else dpsum[i][j] = dp[i][j];
        }
    }
    cout << dp[n][c];
}