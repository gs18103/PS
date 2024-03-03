#include <iostream>
#include <algorithm>

using namespace std;

int dp[3][1010];
int c[3][1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c[0][i] >> c[1][i] >> c[2][i];
    }
    
    for(int i = 1; i <= n; i++) {
        dp[0][i] = min(dp[1][i-1], dp[2][i-1]) + c[0][i];
        dp[1][i] = min(dp[0][i-1], dp[2][i-1]) + c[1][i];
        dp[2][i] = min(dp[0][i-1], dp[1][i-1]) + c[2][i];
    }
    cout << min(min(dp[0][n], dp[1][n]), dp[2][n]);
}