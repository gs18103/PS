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

const int MAX = 1010;
const int INF = 1e9;
const ll LINF = 1e18;

double dp[17][1<<16];
int n, m, sum[1<<16];
bool chk[17][1<<16];
pii bp[17];

double f(int c, int t) {
    if(sum[t] > m) return 0.0;
    if(c == 0) return 1.0;
    if(chk[c][t]) return dp[c][t];
    chk[c][t] = true;
    for(int i = 0; i < n; i++) {
        if(t >> i & 1) continue;
        dp[c][t] = max(dp[c][t], f(c - 1, t | (1 << i)) * bp[i].se / 100.0 + f(c, t | (1 << i)) * (100 - bp[i].se) / 100.0);
    }
    return dp[c][t];
}

void solve() {
    int c;
    cin >> n >> c >> m;
    for(int i = 0; i < n; i++) {
        cin >> bp[i].fi >> bp[i].se;
    }
    for(int i = 0; i < (1 << n); i++) {
        sum[i] = 0;
        for(int j = 0; j < n; j++) {
            if(i >> j & 1) sum[i] += bp[j].fi;
        }
    }
    reset(dp);
    reset(chk);
    cout << f(c, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout.precision(9);
    cout << fixed;

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}