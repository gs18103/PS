#include <bits/stdc++.h>

using namespace std;

int a[202][202];
string ans;

void f(int xs, int xe, int ys, int ye) {
    int sum = 0;
    for(int i = xs; i <= xe; i++) {
        for(int j = ys; j <= ye; j++) {
            sum += a[i][j];
        }
    }
    if(sum == 0) {
        ans += "0";
        return;
    }
    if(sum == (xe - xs + 1) * (ye - ys + 1)) {
        ans += "1";
        return;
    }
    ans += "(";
    int xm = (xs + xe) / 2, ym = (ys + ye) / 2;
    f(xs, xm, ys, ym);
    f(xs, xm, ym + 1, ye);
    f(xm + 1, xe, ys, ym);
    f(xm + 1, xe, ym + 1, ye);
    ans += ")";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 1; j <= n; j++) {
            a[i][j] = tmp[j-1] - '0';
        }
    }
    f(1, n, 1, n);
    cout << ans;
}