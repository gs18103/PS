#include <cstdio>

int arr[101];
int dp[10101];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    dp[0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            if(j - arr[i] >= 0) dp[j] += dp[j-arr[i]];
        }
    }

    printf("%d", dp[k]);
}
