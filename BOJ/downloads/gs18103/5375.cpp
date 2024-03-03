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

ll dp[10101], temp[10101], s[101], p[101], o[101];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) dp[i] = LINF;
    for(int i = 1; i <= m; i++) {
        cin >> s[i] >> p[i] >> o[i];
    }

    for(int i = 1; i <= m; i++) {
        if(s[i] == 0) continue;
        list <pll> dq;
        dq.push_back({dp[0], 0});
        for(int j = 1; j <= n; j++) {
            while(j - dq.front().se > s[i]) dq.pop_front();
            pll val = dq.front();
            temp[j] = min(dp[j], val.fi + j * p[i] + o[i]);
            while(!dq.empty() && dq.back().fi > dp[j] - j * p[i]) dq.pop_back();
            dq.push_back({dp[j] - j * p[i], j});
        }
        for(int j = 1; j <= n; j++) {
            dp[j] = temp[j];
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}