#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    int a = n, b = n;
    for(int i = 1; i <= c; i++) {
        int x, y;
        cin >> x >> y;
        if(x > a || y > b) continue;
        if(x * b >= a * y) a = x;
        else b = y;
    }
    cout << a * b;
}