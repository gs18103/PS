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
const ll mod = 998244353;

struct BIT {
    vector <int> tree;
    int sz;
    
    BIT(int n) {
        tree.resize(n+1);
        sz = n;
    }

    void update(int i, int val) {
        while(i <= sz) {
            tree[i] += val;
            i += (i & -i);
        }
    }

    int cal(int i) {
        int ret = 0;
        while(i > 0) {
            ret += tree[i];
            i -= (i & -i);
        }
        return ret;
    }
};

ll ccw(pll a, pll b, pll c) {
    return (b.fi - a.fi) * (c.se - a.se) - (c.fi - a.fi) * (b.se - a.se);
}

ll dot(pll a, pll b, pll c) {
    return (b.fi - a.fi) * (c.fi - a.fi) + (b.se - a.se) * (c.se - a.se);
}

int n;
ll ans;
pll base;
vector <pll> p0, p;

void solve() {
    p = p0;
    sort(all(p), [](pll a, pll b) {
        if(a == base) return false;
        if(b == base) return true;
        if(a.se == base.se) {
            if(a.fi < base.fi) return true;
            if(b.se > base.se) return true;
            if(b.se < base.se) return false;
            if(b.se == base.se) return false;
        }
        if(b.se == base.se) {
            if(b.fi < base.fi) return false;
            if(a.se > base.se) return false;
            if(a.se < base.se) return true;
        }
        if(a.se < base.se) {
            if(b.se < base.se) return ccw(base, a, b) > 0;
            if(b.se > base.se) return true;
        }
        if(a.se > base.se) {
            if(b.se > base.se) return ccw(base, a, b) > 0;
            if(b.se < base.se) return false;
        }
    });
    p.pop_back();

    int l = 0, r = 0;
    BIT T1(n-1), T2(n-1);
    vector <ll> v;
    for(int i = 0; i < n - 1; i++) {
        v.eb(dot(base, p[i], p[i]));
    }
    sort(all(v));
    
    int idx = 0;
    for(idx = 0; idx < n - 1; idx++) {
        if(p[idx].fi > base.fi && p[idx].se < base.se) break;
        int pos = lower_bound(all(v), dot(base, p[idx], p[idx])) - v.begin() + 1;
        T1.update(pos, 1);
    }
    r = idx + 1;
    for(; idx < n - 1; idx++) {
        if(p[idx].se >= base.se) break;
        while(r < n - 1 && dot(base, p[idx], p[r]) > 0) {
            int pos = lower_bound(all(v), dot(base, p[r], p[r])) - v.begin() + 1;
            T2.update(pos, 1);
            r++;
        }
        while(l < idx && dot(base, p[l], p[idx]) <= 0) {
            int pos = lower_bound(all(v), dot(base, p[l], p[l])) - v.begin() + 1;
            T1.update(pos, -1);         
            l++;
        }
        int pos = lower_bound(all(v), dot(base, p[idx], p[idx])) - v.begin() + 1;
        ans += T1.cal(pos - 1) * T2.cal(pos - 1);
        T1.update(pos, 1);
        if(idx < n - 2) {
            pos = lower_bound(all(v), dot(base, p[idx+1], p[idx+1])) - v.begin() + 1;
            T2.update(pos, -1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    p0.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> p0[i].fi >> p0[i].se;
    }

    for(int i = 0; i < n; i++) {
        base = p0[i];
        solve();
    }
    cout << ans;
}