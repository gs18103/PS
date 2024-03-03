#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[3][10101], c[10101];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    dp[0][1] = 0;
    dp[1][1] = c[1];
    dp[2][1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[1][i] = dp[0][i-1] + c[i];
        dp[2][i] = dp[1][i-1] + c[i];
        dp[0][i] = max({dp[0][i-1], dp[1][i-1], dp[2][i-1]});
    }
    printf("%d", max({dp[0][n], dp[1][n], dp[2][n]}));
}
