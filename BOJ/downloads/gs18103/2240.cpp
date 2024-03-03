#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1010][31];
int arr[1010];

int main()
{
    int t, w;
    scanf("%d %d", &t, &w);
    for(int i = 1; i <= t; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i <= t; i++)
    {
        dp[i][0] = dp[i-1][0] + (arr[i] == 1) * 1;
        for(int j = 1; j <= min(w, i); j++)
        {
            if(arr[i] == j % 2 + 1)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
        }
    }


    int ans = 0;
    for(int i = 0; i <= min(w, t); i++)
    {
        if(ans < dp[t][i]) ans = dp[t][i];
    }

    printf("%d", ans);
}
