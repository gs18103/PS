#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n;
    cin >> n;
    ll ans = 1;
    for(ll i = 2; i * i <= n; i++) {
        ll temp = 1;
        while(n % i == 0) {
            n /= i;
            temp *= i;
        }
        ans *= (temp - temp / i);
    }
    if(n != 1) ans *= (n - 1);
    cout << ans;
}