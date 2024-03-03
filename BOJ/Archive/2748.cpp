#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long f1 = 1, f2 = 1, f3 = 2;
    for(int i = 2; i <= n; i++) {
        long long d = f2 + f3;
        f1 = f2;
        f2 = f3;
        f3 = d;
    }
    printf("%lld", f1);
}