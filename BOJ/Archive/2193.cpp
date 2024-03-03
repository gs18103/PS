#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long int a = 1, b = 1;
    for(int i = 1; i < n; i++)
    {
        long long int t = a;
        a = b;
        b = a + t;
    }
    printf("%lld", a);
}