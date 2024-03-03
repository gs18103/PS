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

ld dist(pll a, pll b) {
    return sqrt((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cout << fixed; cout.precision(10);

    int n;
    cin >> n;
    vector <pll> a(n);
    vector <vector <ld> > dp(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
        dp[i].resize(1<<n);
        fill(all(dp[i]), 1e18);
        dp[i][1<<i] = 0.0;
    }

    for(int i = 1; i < (1 << n); i++) {
        int cnt = n + 1;
        for(int j = 0; j < n; j++) {
            if(i >> j & 1) cnt--;
        }
        if(cnt == n) continue;
        for(int j = 0; j < n; j++) {
            if(!(i >> j & 1)) continue;
            for(int k = 0; k < n; k++) {
                if(j == k) continue;
                if(i >> k & 1) dp[j][i] = min(dp[j][i], dp[k][i^(1<<j)] + cnt * dist(a[j], a[k]));
            }
        }
    }
    ld ans = 1e18;
    for(int i = 0; i < n; i++) ans = min(ans, dp[i][(1<<n)-1]);
    cout << ans;
}