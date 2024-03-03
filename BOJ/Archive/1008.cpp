#include <stdio.h>

int main()
{
    int a, b, cnt = 0;
    scanf("%d %d", &a, &b);
    printf("%d", a / b);
    if(a % b != 0) printf(".");
    while(a % b != 0 && cnt < 11)
    {
        a = a % b;
        a *= 10;
        printf("%d", a/b);
        cnt++;
    }
}
