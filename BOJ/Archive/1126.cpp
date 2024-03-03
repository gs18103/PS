#include <cstdio>
#include <algorithm>

using namespace std;
int h[55];
int dp[55][500010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &h[i]);

    for(int i = 1; i <= 500000; i++) dp[0][i] = -1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= 500000; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= h[i] && dp[i-1][j-h[i]] != -1)
                dp[i][j] = max(dp[i][j], dp[i-1][j-h[i]] + h[i]);
            if(j <= h[i] && dp[i-1][h[i]-j] != -1)
                dp[i][j] = max(dp[i][j], dp[i-1][h[i]-j] + j);
            if(j + h[i] <= 500000 && dp[i-1][j+h[i]] != -1);
                dp[i][j] = max(dp[i][j], dp[i-1][j+h[i]]);
        }
    }

    printf("%d", dp[n][0] ? dp[n][0] : -1);
}
