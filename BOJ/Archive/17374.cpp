#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

void solve() {
    int p, q, a, b, c, d;
    cin >> p >> q >> a >> b >> c >> d;

    int ans = 0, coin = 0;
    coin += d * (q / c);
    int x = (coin - p) / (a + b);
    for(int i = x - 1; i <= x + 1; i++) {
        ans = max(ans, min(p + a * i, coin - b * i));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}