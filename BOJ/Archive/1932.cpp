#include <stdio.h>
#include <algorithm>

using namespace std;

int tri, dp[505][505];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            scanf("%d", &tri);
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + tri;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[n][i]);
    printf("%d", ans);
}
