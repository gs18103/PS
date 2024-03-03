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

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;

int dp[3][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    string s, t;
    cin >> n >> s >> t;
    dp[0][0] = 1 + (t[0] == '1');
    dp[1][0] = 1 + (t[0] == '0');
    dp[2][0] = 0 + (s[0] != t[0]);
    for(int i = 1; i < n; i++) {
        bool b = (t[i] == '1');
        dp[0][i] = min(dp[0][i-1] + (b && t[i-1] == '0'), 
                dp[2][i-1] + 1 + (b && s[i-1] == t[i-1]));
        dp[1][i] = min(dp[1][i-1] + (!b && t[i-1] == '1'), 
                dp[2][i-1] + 1 + (!b && s[i-1] == t[i-1]));
        dp[2][i] = min({
            dp[0][i-1] + (s[i] != t[i] && t[i-1] == '0'), 
            dp[1][i-1] + (s[i] != t[i] && t[i-1] == '1'), 
            dp[2][i-1] + (s[i] != t[i] && t[i-1] == s[i-1])
        });
    }
    cout << min({dp[0][n-1], dp[1][n-1], dp[2][n-1]});
}