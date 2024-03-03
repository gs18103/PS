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

vector <ll> num;

struct SEG {
    vector <pll> tree;
    int sz;
    void Init(int n) {
        tree.resize(4*n+10);
        sz = n;
    }
    void update(int node, int s, int e, int k, ll val) {
        if(s == e) {
            tree[node].fi += val * num[s];
            tree[node].se += val;
            return;
        }
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, val);
        else update(node<<1|1, m+1, e, k, val);
        tree[node].fi = tree[node<<1].fi + tree[node<<1|1].fi;
        tree[node].se = tree[node<<1].se + tree[node<<1|1].se;
    }
    void update(int k, ll val) {update(1, 0, sz-1, k, val);}

    ll cal(int node, int s, int e, ll b) {
        if(s == e) return b / num[s];
        ll tval = tree[node<<1].fi;
        int m = s + e >> 1;
        ll ret;
        if(tval >= b) ret =  cal(node<<1, s, m, b);
        else ret = tree[node<<1].se + cal(node<<1|1, m+1, e, b - tval);
        return ret;
    }
    ll cal(ll b) {return cal(1, 0, sz-1, b);}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; ll b;
    cin >> n >> b;
    vector <pll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
        num.eb(a[i].fi + a[i].se);
        num.eb(a[i].fi / 2 + a[i].se);
    }
    sort(all(num));
    SEG ST;
    ST.Init(2*n);
    for(int i = 0; i < n; i++) {
        int idx = lower_bound(all(num), a[i].fi + a[i].se) - num.begin();
        ST.update(idx, 1);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int idx1 = lower_bound(all(num), a[i].fi + a[i].se) - num.begin();
        int idx2 = lower_bound(all(num), a[i].fi / 2 + a[i].se) - num.begin();
        ST.update(idx1, -1);
        ST.update(idx2, 1);
        ans = max(ans, ST.cal(b));
        ST.update(idx1, 1);
        ST.update(idx2, -1);
    }
    cout << ans;
}