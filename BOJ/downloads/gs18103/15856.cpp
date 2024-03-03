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

ll dp[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }

    if(m == 1) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i][1] == '.') cnt++;
        }
        cout << (1 << cnt) - 1;
        return 0;
    }

    ll ans = 0;
    for(int i = 1; i < (1 << n); i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(i >> j & 1) cnt++;
        }
        dp[0] = 1;
        for(int j = 1; j <= m; j++) {
            int tcnt = 0;
            for(int k = 0; k < n; k++) {
                if((i >> k & 1) && s[k][j] == '.') tcnt++;
            }
            if(j == 1) dp[j] = (((1 << tcnt) - 1)) % mod;
            else dp[j] = ((dp[j-1] + dp[j-2]) * ((1 << tcnt) - 1)) % mod;
        }

        if(n - cnt & 1) ans += (2 * mod - dp[m-1] - dp[m]) % mod;
        else ans += (dp[m-1] + dp[m]) % mod;
        ans %= mod;
    }
    cout << ans;
}