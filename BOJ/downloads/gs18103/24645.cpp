#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        long long n;
        cin >> n;
        long long ans = n / 2;
        while(__gcd(ans, n) != 1) ans--;
        cout << ans << '\n';
    }
}