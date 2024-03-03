#include <stdio.h>

int arr[101010];
int dp[101010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    dp[0] = arr[0];
    int ans = dp[0];
    for(int i = 1; i < n; i++)
    {
        if(dp[i-1] > 0) dp[i] = dp[i-1] + arr[i];
        else dp[i] = arr[i];
        ans = ans > dp[i] ? ans : dp[i];
    }
    printf("%d", ans);
}
