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

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

ll dp[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    if(n <= 2) {
        if(n == 1) cout << 1;
        if(n == 2) cout << 2;
        return 0;
    }
    dp[3] = 1;
    for(int i = 4; i <= n; i++) {
        dp[i]++;
        for(int j = i - 1; j <= n; j += i - 1) {
            if(j > i) dp[j] = (dp[j] + dp[i]) % mod;
            if(j > i && j + 1 <= n) dp[j+1] = (dp[j+1] + dp[i]) % mod;
            if(j + 2 <= n) dp[j+2] = (dp[j+2] + dp[i]) % mod;
        }
    }
    ll ans = 0;
    for(int i = 3; i <= n; i++) {
        ans += dp[i];
        ans %= mod;
    }
    cout << (ans * 2 * n) % mod;
}