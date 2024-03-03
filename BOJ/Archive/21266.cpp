#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

int A[MAX];
ll fact[MAX], inv[MAX], ofact[MAX];

ll mypow(ll a, ll b) {
    ll r = 1;
    while(b > 0) {
        if(b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

ll C(int n, int r) {
    return (((fact[n] * inv[n-r]) % mod) * inv[r]) % mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    fact[0] = ofact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % mod;
        ofact[i] = (ofact[i-1] * (2 * i - 1)) % mod;
    }
    inv[n] = mypow(fact[n], mod - 2);
    for(int i = n; i > 0; i--) {
        inv[i-1] = (inv[i] * i) % mod;
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        if(A[i] == 1) ans += (((ofact[i-1] * ofact[n-i]) % mod) * C(n - 1, i - 1)) % mod;
        ans %= mod;
    }
    cout << ans;
}