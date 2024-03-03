#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()

using namespace std;
typedef pair <int, int> pii;

int dp[303][101010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector <pii> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }

    sort(all(v));
    vector <pii> vv;
    vv.eb(0, 0);
    int r = 0;
    for(int i = 0; i < n; i++) {
        if(v[i].se <= r) continue;
        vv.eb(v[i]);
        r = v[i].se;
    }

    int ans, idx;
    for(int i = 1; i <= min(k, (int)vv.size() - 1); i++) {
        ans = 0;
        idx = 1;
        for(int j = 1; j < vv.size(); j++) {
            while(vv[idx].se < vv[j].fi) idx++;
            dp[i][j] = max({dp[i-1][idx-1] + vv[j].se - vv[j].fi + 1, 
                            dp[i-1][idx] + vv[j].se - vv[idx].se,
                            dp[i][j-1]});
            ans = max(ans, dp[i][j]);
        }
        cout << ans << '\n';
    }
    for(int i = vv.size(); i <= k; i++) {
        cout << ans << '\n';
    }
}