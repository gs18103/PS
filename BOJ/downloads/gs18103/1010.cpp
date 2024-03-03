#include <cstdio>

long long dp[32][32];

int main()
{
    int n, m;
    for(int i = 0; i <= 30; i++) dp[i][0] = 1, dp[0][i] = 1;
    for(int i = 1; i <= 30; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(j == 1) dp[i][j] = i;
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &m);
        printf("%d\n", dp[m][n]);
    }
}
