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
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector <pll> a(n), v;
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(all(a));
    for(auto i : a) {
        while(!v.empty() && v.back().se <= i.se) v.pop_back();
        v.eb(i);
    }
    LineContainer CHT;
    vector <ll> dp(v.size());
    CHT.add(v[0].se, 0);
    dp[0] = v[0].fi * v[0].se;
    for(int i = 1; i < v.size(); i++) {
        CHT.add(v[i].se, dp[i-1]);
        dp[i] = CHT.query(v[i].fi);
    }
    cout << dp.back();
}