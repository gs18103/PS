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

const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    if(m == 1) {
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(all(v));
        int mn = 0, s = 0;
        for(int i = 0; i < n; i++) {
            s += v[i];
            mn = min(mn, s);
        }
        cout << s - mn << '\n';
    }
    else {
        vector <pii> v(n), t1, t2;
        int s1 = 0, s2 = 0, s = 0, ss1 = 0, ss2 = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i].fi >> v[i].se;
            s += v[i].fi + v[i].se;
            if(v[i].fi < 0 && v[i].se < 0) s1 += v[i].fi, s2 += v[i].se;
            else if(v[i].fi < 0) t1.eb(v[i]), ss1 += v[i].fi;
            else if(v[i].se < 0) t2.eb(v[i]), ss2 += v[i].se;
        }
        sort(all(t1), [](pii a, pii b) {return a.fi + a.se < b.fi + b.se;});
        sort(all(t2), [](pii a, pii b) {return a.fi + a.se < b.fi + b.se;});
        int val = s1 + s2 + ss2;
        int ans = max(s - s1 - s2 - ss1, s - s1 - s2 - ss2);
        for(pii x : t1) {
            if(x.fi + x.se >= 0) break;
            val += x.fi + x.se;
            ans = max(ans, s - val);
        }
        val = s1 + s2 + ss1;
        for(pii x : t2) {
            if(x.fi + x.se >= 0) break;
            val += x.fi + x.se;
            ans = max(ans, s - val);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}