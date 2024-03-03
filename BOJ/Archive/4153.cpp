#include <bits/stdc++.h>

using namespace std;

int p[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(1) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
        if(a * a + b * b == c * c) {
            cout << "right\n";
        }
        else cout << "wrong\n";
    }
}