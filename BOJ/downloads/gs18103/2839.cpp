#include <stdio.h>

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    while(n % 5 != 0 && n > 0)
    {
        n -= 3;
        cnt++;
    }
    if(n < 0) printf("-1");
    else printf("%d", cnt + n / 5);
}