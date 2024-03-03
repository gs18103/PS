#include <cstdio>

int main()
{
    long long a;
    long long b, c;

    scanf("%lld %lld %lld", &a, &b, &c);

    a %= c;
    long long ans = 1;
    while(b > 0)
    {
        if(b % 2 == 1) ans = (ans * a) % c;
        a = (a * a) % c;
        b /= 2;
    }
    printf("%lld", ans % c);
}
