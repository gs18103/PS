#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int mn = 1e9, mx = -1e9;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    cout << mn << ' ' << mx << endl;
}