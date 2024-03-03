#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll a[55];

struct cmp {
    bool operator() (pll x, pll y) {
        return x.fi * y.se < x.se * y.fi;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed; cout.precision(15);
    
    int n, m;
    priority_queue <pll, vector <pll>, cmp> pq;
    double mn = 1e9;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mn = min(mn, (double)a[i]);
        pq.emplace(a[i], 1);
    }
    cin >> m;
    
    double ans = pq.top().fi - mn;
    for(int i = 1; i <= m; i++) {
        pll x = pq.top();
        pq.pop();
        x.se++;
        mn = min(mn, (double)x.fi / x.se);
        pq.emplace(x);
        ans = min(ans, (double) pq.top().fi / pq.top().se - mn);
    }
    
    cout << ans;

    return 0;
}