#include <cstdio>

int arr[101];
int dp[101][1010];

int main()
{
    int n, s, m;
    scanf("%d %d %d", &n, &s, &m);

    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    dp[0][s] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(j - arr[i] >= 0 && dp[i-1][j-arr[i]] == 1) dp[i][j] = 1;
            if(j + arr[i] <= m && dp[i-1][j+arr[i]] == 1) dp[i][j] = 1;
        }
    }

    int ans = -1;
    for(int i = 0; i <= m; i++)
    {
        if(dp[n][i] == 1) ans = i;
    }

    printf("%d", ans);
}
