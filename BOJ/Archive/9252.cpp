#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[1010][1010];
char a[1010], b[1010];
   char s[1010];

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
    printf("%d\n", dp[la][lb]);

    int len = dp[la][lb];

    for(int i = la; i > 0; i--)
    {
        for(int j = 1; j <= lb; j++)
        {
            if(dp[i][j] == len && dp[i][j-1] == len - 1 && dp[i-1][j] == len - 1 && dp[i-1][j-1] == len - 1)
            {
                len--;
                lb = j;
                s[len] = a[i-1];
            }
        }
    }
    printf("%s", s);
}
