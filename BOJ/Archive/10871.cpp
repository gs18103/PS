#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        int y;
        cin >> y;
        if(y < x) cout << y << ' ';
    }
}