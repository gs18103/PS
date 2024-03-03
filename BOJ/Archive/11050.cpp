#include <cstdio>

int c[1010][1010];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i <= n; i++)
    {
        c[i][0] = 1;
        for(int j = 1; j <= i; j++)
            c[i][j] += c[i-1][j-1] + c[i-1][j];
    }

    printf("%d", c[n][k]);
}
