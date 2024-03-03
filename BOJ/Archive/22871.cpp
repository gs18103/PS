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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <ll> a(n+1), dp(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i] = LINF;
        for(int j = 1; j < i; j++) {
            dp[i] = min(dp[i], max(dp[j], (i - j) * (1 + abs(a[i] - a[j]))));
        }
    }
    cout << dp[n];
}