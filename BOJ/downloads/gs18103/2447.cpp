#include <bits/stdc++.h>

using namespace std;

int a[3030][3030];

void f(int xs, int xe, int ys, int ye) {
    if(xs == xe) {
        a[xs][ys] = 1;
        return;
    }
    int xm1 = (2 * xs + xe) / 3, xm2 = (xs + 2 * xe) / 3;
    int ym1 = (2 * ys + ye) / 3, ym2 = (ys + 2 * ye) / 3;
    
    f(xs, xm1, ys, ym1);
    f(xs, xm1, ym1 + 1, ym2);
    f(xs, xm1, ym2 + 1, ye);
    f(xm1 + 1, xm2, ys, ym1);
    f(xm1 + 1, xm2, ym2 + 1, ye);
    f(xm2 + 1, xe, ys, ym1);
    f(xm2 + 1, xe, ym1 + 1, ym2);
    f(xm2 + 1, xe, ym2 + 1, ye);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    f(1, n, 1, n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j]) cout << "*";
            else cout << " ";
        }
        cout << '\n';
    }
}