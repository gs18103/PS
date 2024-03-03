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

int dp[MAX], shift;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        dp[i] = INF;
    }
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int p;
            cin >> p;
            shift++;
            dp[p] = -shift;
        }
        if(t == 2) {
            int p, q;
            cin >> p >> q;
            dp[q] = min(dp[q], dp[p]);
            dp[p]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(dp[i] + shift > n) cout << "-1 ";
        else cout << dp[i] + shift << ' ';
    }
}