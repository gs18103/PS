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

int dp[1010][1010], s[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int a, d;
    cin >> a >> d;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j+1] = max(dp[i][j+1], dp[i][j] + s[j+1]);
            dp[i+1][min(j+d, n)] = max(dp[i+1][min(j+d, n)], dp[i][j] + a);
        }
        if(dp[i][n] >= m) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}