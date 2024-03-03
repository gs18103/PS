#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

ll mymul(ll a, ll b, ll c) {
    return (ll)(((__int128_t)a * (__int128_t)b) % c);
}

ll mypow(ll a, ll b, ll c) {
    ll r = 1;
    while(b) {
        if(b & 1) r = mymul(a, r, c);
        a = mymul(a, a, c);
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << mypow(a, b, c);
}