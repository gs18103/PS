#include <cstdio>

int p[101];

int fin(int k)
{
    if(p[k] == 0 || p[k] == k) return p[k] = k;
    else return p[k] = fin(p[k]);
}

void uni(int x, int y)
{
    x = fin(x);
    y = fin(y);
    if(x < y) p[y] = x;
    else p[x] = y;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        uni(x, y);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(fin(i) == 1) cnt++;

    printf("%d", cnt - 1);
}
