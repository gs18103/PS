#include <bits/stdc++.h>

using namespace std;

int p[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while(q--) {
        int h, w, n;
        cin >> h >> w >> n;
        cout << ((n - 1) % h + 1) * 100 + ((n - 1) / h) + 1 << '\n';
    }
}