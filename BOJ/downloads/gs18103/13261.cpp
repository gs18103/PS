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

const int MAX = 8080;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

ll c[MAX], dp[808][MAX], sum[MAX];

void dnc(int s, int e, int l, int r, int t) {
    if(s > e) return;
    int m = (s + e) >> 1, idx = -1;
    dp[t][m] = LINF;
    for(int i = l; i <= min(r, m); i++) {
        if(dp[t][m] > dp[t-1][i-1] + (sum[m] - sum[i-1]) * (m - i + 1)) {
            dp[t][m] = dp[t-1][i-1] + (sum[m] - sum[i-1]) * (m - i + 1);
            idx = i;
        }
    }

    dnc(s, m - 1, l, idx, t);
    dnc(m + 1, e, idx, r, t);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, g;
    cin >> n >> g;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        sum[i] = sum[i-1] + c[i];
    }
    for(int i = 1; i <= n; i++) {
        dp[1][i] = sum[i] * i;
    }
    for(int i = 2; i <= g; i++) {
        dnc(1, n, 1, n, i);
    }
    cout << dp[g][n];
}