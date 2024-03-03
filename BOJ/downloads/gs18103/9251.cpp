#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[1010][1010];
char a[1010], b[1010];

int main()
{
    scanf("%s %s", a, b);
    int la = strlen(a), lb = strlen(b);
    for(int i = 0; i < la; i++)
    {
        for(int j = 0; j < lb; j++)
        {
            if(a[i] == b[j])
            {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else
            {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    printf("%d", dp[la][lb]);
}
