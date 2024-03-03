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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

pii operator + (pii &X, pii &Y) { return pii(X.fi + Y.fi, X.se + Y.se); }
pii operator - (pii &X, pii &Y) { return pii(X.fi - Y.fi, X.se - Y.se); }

struct Point {
    double x, y;
    int idx;
    Point(double _x, double _y, int _idx) : x(_x), y(_y), idx(_idx) {}

    bool operator < (const Point &p) const {
        double sgn = x * p.x;
        if(abs(sgn) < 1e-18) {
            if(abs(p.x) < 1e-12 && p.y < 0.0) return false;
            if(abs(x) < 1e-12 && y < 0.0) return true;
            return x * p.y - y * p.x > 0.0;
        }
        else if(x * p.x < 0.0) return x > 0.0;
        else return x * p.y - y * p.x > 0.0;
    }
};

struct BIT {
    vector <int> tree;
    int sz;
    BIT(int n) : sz(n) {
        tree.resize(n+1);
    }
    
    void clear() {
        for(int &i : tree) i = 0;
    }

    void update(int i, int val) {
        for(; i <= sz; i += (i & -i)) tree[i] += val;
    }

    int cal(int l, int r) {
        if(l > sz) exit(1);
        if(r > sz) exit(1);
        int ret = 0;
        if(l > r) swap(l, r);
        for(; r > 0; r -= (r & -r)) ret += tree[r];
        for(l--; l > 0; l -= (l & -l)) ret -= tree[l];
        return ret;
    }
};

ll dist(pii a, pii b) {
    return (ll)(a.fi - b.fi) * (a.fi - b.fi) + (ll)(a.se - b.se) * (a.se - b.se);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, d;
    cin >> n >> d; 
    vector <pii> v(n+1);
    vector <vector <bool>> chk(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i].fi >> v[i].se;
        chk[i].resize(n+1);
    } 

    BIT T(n);
    for(int i = 1; i <= n; i++) {
        vector <Point> tv;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            v[j].fi -= v[i].fi, v[j].se -= v[i].se;
            tv.eb(v[j].fi, v[j].se, n + j);
            if((ll)v[j].fi * v[j].fi + (ll)v[j].se * v[j].se <= (ll)d * d) T.update(j, 1);
            else {
                double vv = (double)((ll)v[j].fi * v[j].fi + (ll)v[j].se * v[j].se);
                double temp = sqrt(vv - (double)d * d);
                tv.eb(temp * v[j].fi + (double)d * v[j].se, temp * v[j].se - (double)d * v[j].fi, j);
                tv.eb(temp * v[j].fi - (double)d * v[j].se, temp * v[j].se + (double)d * v[j].fi, -j);
            }
            v[j].fi += v[i].fi, v[j].se += v[i].se;
        }
        sort(all(tv));
        vector <bool> c(n+1);
        for(Point &p : tv) {
            if(p.idx > n) continue;
            if(p.idx < 0 && !c[abs(p.idx)]) T.update(-p.idx, 1);
            c[abs(p.idx)] = true;
        }
        for(Point &p : tv) {
            if(p.idx > n) {
                p.idx -= n;
                if(T.cal(i, p.idx) == abs(i - p.idx)) chk[i][p.idx] = true;
            }
            else if(p.idx > 0) T.update(p.idx, 1);
            else T.update(-p.idx, -1);
        }
        T.clear();
    }

    vector <int> dp(n+1);
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = n;
        for(int j = 1; j < i; j++) {
            if(chk[i][j] && chk[j][i]) dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    cout << dp[n] << endl;
}