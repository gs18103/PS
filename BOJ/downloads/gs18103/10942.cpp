#include <cstdio>

int dp[2020][2020];
int arr[2020];

int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] == arr[i+1]) dp[i][i+1] = 1;
    }

    for(int i = 2; i < n; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            if(dp[j+1][j+i-1] == 1 && arr[j] == arr[j+i]) dp[j][j+i] = 1;
        }
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s-1][e-1]);
    }
}
