#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    int t = (n % 10) * 10 + ((n % 10) + (n / 10)) % 10, cnt = 1;
    while(t != n) {
        t = (t % 10) * 10 + ((t % 10) + (t / 10)) % 10;
        cnt++;
    }
    printf("%d", cnt);
}
