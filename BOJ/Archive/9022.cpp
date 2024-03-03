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

/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k > o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { 
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m < y->m ? inf : -inf; 
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

void solve() {
    int n;
    cin >> n;
    vector <pll> a(n), v;
    vector <ll> dp(n+1);
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        y = abs(y);
        a[i] = {x-y, x+y};
    }
    sort(all(a), [](pll x, pll y) {
        if(x.fi == y.fi) return x.se > y.se;
        return x.fi < y.fi;
    });
    v.eb(0, -LINF);
    for(int i = 0; i < n; i++) {
        if(v.back().se < a[i].se) v.eb(a[i]);
    }
    n = v.size()- 1;
    LineContainer CHT;
    for(int i = 1; i <= n; i++) {
        CHT.add(-2 * v[i].fi, v[i].fi * v[i].fi + dp[i-1]);
        dp[i] = CHT.query(v[i].se) + v[i].se * v[i].se;
    }
    cout << (double)dp[n] / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed; cout.precision(1);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}