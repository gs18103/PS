#include <cstdio>

int dp[31];

int main()
{
    int n;
    scanf("%d", &n);
    dp[1] = 1;
    dp[2] = 3;
    if(n <= 2)
    {
        printf("%d", dp[n]);
        return 0;
    }
    for(int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2] * 2;

    if(n % 2 == 0) printf("%d", (dp[n] - dp[n/2] - 2 * dp[n/2-1]) / 2 + dp[n/2] + 2 * dp[n/2-1]);
    else printf("%d", (dp[n] - dp[n/2]) / 2 + dp[n/2]);
}
