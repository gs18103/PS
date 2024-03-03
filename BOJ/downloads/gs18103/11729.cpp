#include <stdio.h>

void H(int n, int f, int t, int r) {
    if(n == 1) {
        printf("%d %d\n", f, t);
        return;
    }
    H(n-1, f, r, t);
    printf("%d %d\n", f, t);
    H(n-1, r, t, f);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    H(n, 1, 3, 2);
}
