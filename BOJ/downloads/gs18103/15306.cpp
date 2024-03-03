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

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

ll dp[33][MAX], ans[33], fact[MAX], inv[MAX];

ll mypow(ll a, ll b) {
    ll ret = 1;
    while(b > 0) {
        if(b & 1) ret = (ret * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ret;
}

ll C(int n, int r) {
    return (((fact[n] * inv[r]) % mod) * inv[n-r]) % mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, l, r;
    cin >> n >> l >> r;
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    inv[n] = mypow(fact[n], mod - 2);
    for(int i = n; i >= 1; i--) {
        inv[i-1] = (inv[i] * i) % mod;
    }
    
    dp[0][0] = dp[0][1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[0][i] = (dp[0][i-1] + (ll)(i - 1) * dp[0][i-2]) % mod;
    }
    ans[0] = dp[0][n];

    dp[1][3] = 1;
    for(int i = 4; i <= n; i++) {
        dp[1][i] = (dp[1][i-1] * (ll)(i - 1)) % mod;
    }

    for(int i = 2; i <= min(30, n / 3); i++) {
        dp[i][3*i] = (dp[i-1][3*(i-1)] * C(3 * i - 1, 2)) % mod;
        for(int j = 3 * i + 1; j <= n; j++) {
            dp[i][j] = (dp[i][j-1] * (j - 1) + dp[i-1][j-3] * C(j - 1, 2)) % mod;
        }
    }

    for(int i = 1; i <= min(30, n / 3); i++) {
        for(int j = 3 * i; j <= n; j++) {
            ans[i] = (ans[i] + ((dp[i][j] * dp[0][n-j]) % mod) * C(n, j)) % mod;
        }
    }

    ll rans = 0;
    for(int i = 0; i <= 30; i++) {
        if((1 << i) >= l && (1 << i) <= r) rans = (rans + ans[i]) % mod;
    }
    cout << rans;
}