#include <bits/stdc++.h>

using namespace std;

int a[202][202];
int w = 0, b = 0;

void f(int xs, int xe, int ys, int ye) {
    int sum = 0;
    for(int i = xs; i <= xe; i++) {
        for(int j = ys; j <= ye; j++) {
            sum += a[i][j];
        }
    }
    if(sum == 0) {
        w++;
        return;
    }
    if(sum == (xe - xs + 1) * (ye - ys + 1)) {
        b++;
        return;
    }
    int xm = (xs + xe) / 2, ym = (ys + ye) / 2;
    f(xs, xm, ys, ym);
    f(xs, xm, ym + 1, ye);
    f(xm + 1, xe, ys, ym);
    f(xm + 1, xe, ym + 1, ye);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    f(1, n, 1, n);
    cout << w << '\n' << b;
}