#include <bits/stdc++.h>

using namespace std;

long long gcd(long long x, long long y) {
    if(!y) return x;
    return gcd(y, x % y);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    long long n, m;
    cin >> n >> m;
    cout << n * m / gcd(n, m);
}