#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define em emplace

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

ll gcd(ll x, ll y) {
    if(!y) return x;
    return gcd(y, x % y);
}

ll Euclid(ll p, ll q, ll n) {
    if(!p) return 0;
    if(p >= q) return n * (n + 1) / 2 * (p / q) + Euclid(p % q, q, n);
    return n * (p * n / q) + n / q - Euclid(q, p, p * n / q);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        ll p, q, n;
        cin >> p >> q >> n;
        ll g = gcd(p, q);
        cout << p * n * (n + 1) / 2 - q * Euclid(p / g, q / g, n) << '\n';
    }
}