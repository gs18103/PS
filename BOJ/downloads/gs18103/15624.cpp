#include <stdio.h>

const int mod = 1000000007; // const : 상수라고 생각하면 된다.

int dp[1010101];

int main() {
    int n;
    scanf("%d", &n);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    printf("%d", dp[n]);
}
