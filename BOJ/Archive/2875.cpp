#include <cstdio>
#include <algorithm>

int num[10101];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int cnt = 0;
    while(n + m >= k + 3 && m > 0 && n >= 2)
    {
        n -= 2;
        m -= 1;
        cnt++;
    }
    printf("%d", cnt);
}
