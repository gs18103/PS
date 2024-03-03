#include <cstdio>
#include <cstring>

int dp[202][202];
char x[202];

char open[5] = "({[";
char close[5] = ")}]";

long long f(int i, int j)
{
    if(i > j) return 1;
    long long ans = dp[i][j];
    if(ans != -1) return ans;
    ans = 0;
    for(int k = i + 1; k <= j; k+= 2)
    {
        for(int l = 0; l < 3; l++)
        {
            if((x[i] == open[l] || x[i] == '?') && (x[k] == close[l] || x[k] == '?'))
            {
                long long temp = f(i + 1, k - 1) * f(k + 1, j);
                ans += temp;
                if(ans >= 100000)
                    ans = 100000 + ans % 100000;
            }
        }
    }

    return dp[i][j] = ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", x);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }
    long long ans = f(0, n - 1);
    if(ans >= 100000)printf("%05lld", ans % 100000);
    else printf("%lld", ans);
}
