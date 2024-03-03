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
const ll mod = 1e9+7;

ll a[1010];

ll mypow(ll a, ll b) {
    ll r = 1;
    while(b) {
        if(b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        ll tmp = 1;
        for(int j = 1; j <= m; j++) {
            if(i == j) continue;
            tmp = tmp * (a[i] - a[j] + mod) % mod;
        }
        tmp = mypow(tmp, mod - 2);
        tmp *= mypow(a[i], m + n - 1);
        tmp %= mod;
        ans += tmp;
        ans %= mod;
    }

    cout << ans;
}