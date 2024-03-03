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

const int MAX = 1010101;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll mod = 998244353;

int dp[43];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 42; i++) {
        dp[i] = 2 * dp[i-1] - dp[i-3];
    }
    while(q--) {
        int ans = 42, v;
        cin >> v;
        for(int i = 1; i <= 42; i++) {
            if(dp[i] > v) {
                ans = i - 1;
                break;
            }
        }
        cout << ans << '\n';
    }
}