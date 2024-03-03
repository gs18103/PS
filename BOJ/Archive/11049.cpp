#include <cstdio>

int arr[2][505];
int dp[505][505];

int f(int i, int j)
{
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = dp[i][j];
    for(int k = i; k <= j - 1; k++)
    {
        int temp = f(i, k) + f(k + 1, j) + arr[0][i] * arr[1][k] * arr[1][j];
        if(ans == -1 || ans > temp) ans = temp;
    }

    return dp[i][j] = ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &arr[0][i], &arr[1][i]);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = -1;

    printf("%d\n", f(1, n));

}