#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[2520][2520];
char arr[2520];
int ndp[2520];

int main()
{
    int n;
    scanf("%s", arr);

    n = strlen(arr);

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

    ndp[0] = 1;

    for(int i = 1; i < n; i++)
    {
        ndp[i] = ndp[i-1] + 1;
        if(dp[0][i] == 1) ndp[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(dp[j][i] == 1) ndp[i] = min(ndp[i], ndp[j-1] + 1);
        }
    }

    printf("%d", ndp[n-1]);
}
