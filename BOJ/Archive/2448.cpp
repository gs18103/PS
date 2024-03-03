#include <bits/stdc++.h>

using namespace std;

bool a[4040][8080];

void f(int xs, int xe, int ys, int ye) {
    if(xe - xs == 2) {
        a[xs][ys+2] = 1;
        a[xs+1][ys+1] = a[xs+1][ys+3] = 1;
        a[xs+2][ys] = a[xs+2][ys+1] = a[xs+2][ys+2] = a[xs+2][ys+3] = a[xs+2][ys+4] = 1;
        return;
    }
    int xm = (xs + xe) / 2;
    int ym = (ys + ye) / 2;
    
    f(xs, xm, (ys * 3 + ye) / 4 + 1, (ys + ye * 3) / 4);
    f(xm + 1, xe, ys, ym - 1);
    f(xm + 1, xe, ym + 1, ye);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    f(1, n, 1, 2*n-1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 2 * n - 1; j++) {
            if(a[i][j]) cout << "*";
            else cout << " ";
        }
        cout << '\n';
    }
}