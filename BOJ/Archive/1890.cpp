#include <cstdio>

int arr[101][101];
long long dp[101][101];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0) continue;
            for(int k = 0; k < j; k++)
            {
                if(k + arr[i][k] == j)
                {
                    dp[i][j] += dp[i][k];
                }
            }
            for(int k = 0; k < i; k++)
            {
                if(k + arr[k][j] == i)
                {
                    dp[i][j] += dp[k][j];
                }
            }
        }
    }

    printf("%lld", dp[n-1][n-1]);
}
