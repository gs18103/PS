#include <cstdio>

int main()
{
    double d1, d2, k;
    scanf("%lf %lf %lf", &k, &d1, &d2);
    printf("%lf", k * k - (d1-d2)*(d1-d2)/4);
}