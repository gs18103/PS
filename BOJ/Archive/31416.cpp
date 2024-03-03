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
typedef pair <int, ll> pil;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int T_A, T_B, V_A, V_B;
    cin >> T_A >> T_B >> V_A >> V_B;

    int ans = INF;
    for(int i = 0; i <= V_A; i++) {
        ans = min(ans, max(T_A * i, T_A * (V_A - i) + T_B * V_B));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}