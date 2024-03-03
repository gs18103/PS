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

int a[2020];
int dp[2020][2020];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = n; j >= i; j--) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i] * (n - j + i));
            dp[i][j-1] = max(dp[i][j-1], dp[i][j] + a[j] * (n - j + i));
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][i] + a[i] * n);
    }
    cout << ans;
}