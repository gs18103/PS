#include <cstdio>
#include <algorithm>

using namespace std;

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

    dp[0] = 0;
    for(int i = 1; i <= k; i++)
        dp[i] =   0x0fffffff;

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(j - arr[i] >= 0) dp[j] = min(dp[j], dp[j-arr[i]] + 1);
        }
    }

    if(dp[k] == 0x0fffffff) printf("-1");
    else printf("%d", dp[k]);
}
