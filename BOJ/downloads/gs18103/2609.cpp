#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
    if(!y) return x;
    return gcd(y, x % y);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    cout << gcd(n, m) << ' ' << n * m / gcd(n, m);
}