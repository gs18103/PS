#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

ll a[1010], b[1010], dp[1010][1010];

bool solve() {
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0) return false;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        if(b[i] < a[i]) b[i] += m;
        b[i] -= a[i];
    }

    for(int i = 0; i <= n; i++) {
        dp[1][i] = m * i + b[1];
    }
    for(int i = 2; i <= n; i++) {
        int idx = 0; ll mn = LINF;
        for(int j = 0; j <= n; j++) {
            if(b[i-1] <= b[i]) mn = min(mn, dp[i-1][j] + m * (n + 1 - j) - b[i-1]);
            dp[i][j] = mn - m * (n + 1 - j) + b[i];
            if(b[i-1] > b[i]) mn = min(mn, dp[i-1][j] + m * (n + 1 - j) - b[i-1]);
        }
        idx = n, mn = LINF;
        for(int j = n; j >= 0; j--) {
            if(b[i-1] >= b[i]) mn = min(mn, dp[i-1][j]);
            dp[i][j] = min(dp[i][j], mn);
            if(b[i-1] < b[i]) mn = min(mn, dp[i-1][j]);
        }
    }
    ll ans = LINF;
    for(int i = 0; i <= n; i++) ans = min(ans, dp[n][i]);
    cout << ans << '\n';

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    while(solve()) ;
}