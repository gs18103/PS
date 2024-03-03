#include <bits/stdc++.h>

using namespace std;

bool row[15], b1[31], b2[31];
int cnt = 0, n;

void f(int k) {
    if(k == n + 1) {
        cnt++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(row[i] || b1[k+i] || b2[k+(n-1-i)]) continue;
        row[i] = true;
        b1[k+i] = true;
        b2[k+n-1-i] = true;
        f(k + 1);
        row[i] = false;
        b1[k+i] = false;
        b2[k+n-1-i] = false;
    }
}

int main() {
    scanf("%d", &n);
    f(1);
    printf("%d", cnt);
}
