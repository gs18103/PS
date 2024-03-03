#include <cstdio>

char a[55][55];
char b[55][55];

void change(int x, int y)
{
    for(int i = x; i < x + 3; i++)
        for(int j = y; j < y + 3; j++)
            if(a[i][j] == '0')
                a[i][j] = '1';
            else
                a[i][j] = '0';
}

int main()
{
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", a[i]);
    for(int i = 0; i < n; i++)
        scanf("%s", b[i]);

    for(int i = 0; i < n - 2; i++)
        for(int j = 0; j < m - 2; j++)
            if(a[i][j] != b[i][j])
            {
                change(i, j);
                cnt++;
            }

    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] != b[i][j]) flag = true;
        }
    }
    if(flag) printf("-1");
    else printf("%d", cnt);
}
