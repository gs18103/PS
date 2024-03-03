#include <cstdio>

int mat[6][6];
int temp[6][6];
int ans[6][6];

int main()
{
    int n;
    long long b;
    scanf("%d %lld", &n, &b);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
            if(i == j)ans[i][j] = 1;
        }
    }

    while(b > 0)
    {
        if(b & 1)
        {

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    temp[i][j] = 0;
                    for(int k = 0; k < n; k++)
                    {
                        temp[i][j] += ans[i][k] * mat[k][j];
                        temp[i][j] %= 1000;
                    }
                }
            }
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    ans[i][j] = temp[i][j];
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                temp[i][j] = 0;
                for(int k = 0; k < n; k++)
                {
                    temp[i][j] += mat[i][k] * mat[k][j];
                    temp[i][j] %= 1000;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                mat[i][j] = temp[i][j];
            }
        }

        b /= 2;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}
