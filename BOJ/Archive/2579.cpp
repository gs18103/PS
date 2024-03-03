#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[3][303], c[303];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    dp[1][1] = c[1];
    dp[1][2] = c[2];
    dp[2][2] = c[1] + c[2];
    for(int i = 3; i <= n; i++) {
        dp[1][i] = max(dp[1][i-2], dp[2][i-2]) + c[i];
        dp[2][i] = dp[1][i-1] + c[i];
    }
    printf("%d", max(dp[1][n], dp[2][n]));
}
