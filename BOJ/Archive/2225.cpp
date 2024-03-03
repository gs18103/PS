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

const int MAX = 202;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

int dp[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    for(int i = 1; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            for(int l = 0; l <= j; l++) {
                dp[i][j] += dp[i-1][l];
                dp[i][j] %= INF;
            }
        }
    }
    cout << dp[k][n];
}