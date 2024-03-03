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

const int MAX = 303030;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

void ins(list <pll> &dq, pll val) {
    while(!dq.empty() && dq.back() > val) {
        dq.pop_back();
    }
    dq.eb(val);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, s, e, t;
    cin >> n >> m >> s >> e >> t;
    vector <vector <ll> > c(n+1), dp(n+1), sum(n+1);
    vector <int> p(n+1);
    for(int i = 1; i <= n; i++) {
        c[i].resize(m+1);
        dp[i].resize(m+1);
        sum[i].resize(m+2);
        for(int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
        for(int j = m; j >= 1; j--) {
            sum[i][j] = sum[i][j+1] + c[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector <list <pll> > dq(n+1);
    for(int i = 1; i <= n; i++) {
        dq[i].eb(sum[i][1], 0);
    }
    for(int j = 1; j < s; j++) {
        for(int i = 1; i <= n; i++) {
            dp[i][j] = 210000010;
        }
    }

    for(int j = s; j < m; j++) {
        for(int i = 1; i <= n; i++) {
            while(dq[i].front().se < j - e) dq[i].pop_front();
            dp[i][j] = dq[i].front().fi - sum[i][j+1];
        }
        pll mn1 = {210000010, 0}, mn2 = {210000010, 0}, mn3{210000010, 0};
        for(int i = 1; i <= n; i++) {
            pll tmp = {dp[i][j-s+1], i};
            if(tmp < mn3) {
                mn3 = tmp;
                if(mn2 > mn3) swap(mn2, mn3);
                if(mn1 > mn2) swap(mn1, mn2);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(mn1.se != i && mn1.se != p[i]) {
                ins(dq[i], {mn1.fi + sum[i][j-s+2] + t, j - s + 1});
            }
            else if(mn2.se != i && mn2.se != p[i]) {
                ins(dq[i], {mn2.fi + sum[i][j-s+2] + t, j - s + 1});
            }
            else {
                ins(dq[i], {mn3.fi + sum[i][j-s+2] + t, j - s + 1});
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        while(dq[i].front().se < m - e) dq[i].pop_front();
    }
    for(int j = m; j <= m + s - 2; j++) {
        pll mn1 = {210000010, 0}, mn2 = {210000010, 0}, mn3{210000010, 0};
        for(int i = 1; i <= n; i++) {
            pll tmp = {dp[i][j-s+1], i};
            if(tmp < mn3) {
                mn3 = tmp;
                if(mn2 > mn3) swap(mn2, mn3);
                if(mn1 > mn2) swap(mn1, mn2);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(mn1.se != i && mn1.se != p[i]) {
                ins(dq[i], {mn1.fi + sum[i][j-s+2] + t, j - s + 1});
            }
            else if(mn2.se != i && mn2.se != p[i]) {
                ins(dq[i], {mn2.fi + sum[i][j-s+2] + t, j - s + 1});
            }
            else {
                ins(dq[i], {mn3.fi + sum[i][j-s+2] + t, j - s + 1});
            }
        }
    }

    ll ans = 210000000;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, dq[i].front().fi);
    }
    cout << ans << endl;
}