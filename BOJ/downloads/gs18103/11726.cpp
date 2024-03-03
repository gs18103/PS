#include <stdio.h>

int memo[1010];

int f(int k)
{
    if(memo[k] != 0) return memo[k];
    if(k == 1) return 1;
    if(k == 2) return 2;
    return memo[k] = (f(k - 1) + f(k - 2)) % 10007;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", f(n) % 10007);
}