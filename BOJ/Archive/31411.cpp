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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector <vector <int>> d(n), dp(n);
    for(int i = 0; i < n; i++) {
        d[i].resize(k), dp[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> d[i][j];
        }
        sort(all(d[i]));
    }
    vector <int> x(n);
    int ans = INF;
    for(int i = 1; i <= 100000; i++) {
        int mx = 0;
        for(int j = 0; j < n; j++) {
            while(x[j] < k && d[j][x[j]] < i) x[j]++;
            if(x[j] == k) mx = INF;
            else mx = max(mx, d[j][x[j]]);
        }
        ans = min(ans, mx - i);
    }
    cout << ans << '\n';
}