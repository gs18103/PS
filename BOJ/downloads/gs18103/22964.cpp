#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 1010101;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll mod = 998244353;

ll mul(ll a, ll b) {
    a %= mod;
    b %= mod;
    return (a * b) % mod;
}

ll mypow(ll a, ll b) {
    ll ret = 1;
    while(b > 0) {
        if(b & 1) ret = mul(ret, a);
        b >>= 1;
        a = mul(a, a);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, k, x;
    cin >> n >> k >> x;
    ll cal = mul(mul(k, mypow(x * (x + 1) / 2, 2)), mypow(x, n + k - 2));
    for(int i = 1; i <= n - k + 1; i++) {
        cout << cal << ' ';
    }
}