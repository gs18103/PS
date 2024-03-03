#include <bits/stdc++.h>

using namespace std;

bool a[3300][3300];

void f(int xs, int xe, int ys, int ye) {
    if(xe - xs == 1) {
        a[xs][ys] = true;
        return;
    }
    int d = (xe - xs) / 5;
    f(xs + 0 * d, xs + 1 * d, ys + 2 * d, ys + 3 * d);
    f(xs + 1 * d, xs + 2 * d, ys + 2 * d, ys + 3 * d);
    f(xs + 2 * d, xs + 3 * d, ys + 0 * d, ys + 1 * d);
    f(xs + 2 * d, xs + 3 * d, ys + 1 * d, ys + 2 * d);
    f(xs + 2 * d, xs + 3 * d, ys + 2 * d, ys + 3 * d);
    f(xs + 2 * d, xs + 3 * d, ys + 3 * d, ys + 4 * d);
    f(xs + 2 * d, xs + 3 * d, ys + 4 * d, ys + 5 * d);
    f(xs + 3 * d, xs + 4 * d, ys + 1 * d, ys + 2 * d);
    f(xs + 3 * d, xs + 4 * d, ys + 2 * d, ys + 3 * d);
    f(xs + 3 * d, xs + 4 * d, ys + 3 * d, ys + 4 * d);
    f(xs + 4 * d, xs + 5 * d, ys + 1 * d, ys + 2 * d);
    f(xs + 4 * d, xs + 5 * d, ys + 3 * d, ys + 4 * d);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    int sz = 1;
    for(int i = 0; i < n; i++) sz *= 5;
    f(0, sz, 0, sz);
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            if(a[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}