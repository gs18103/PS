#include  <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

struct SEG {
    vector <int> tree;
    int sz;
    bool base;

    SEG(int n, bool _base = true) : base(_base) {
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.resize(sz<<1);
    }

    void update(int k, int val) {
        int node = k + sz - base;
        tree[node] += val;
        while(node >>= 1) tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    int cal(int l, int r) {
        int ret = 0;
        for(l += sz - base, r += sz - base; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) ret += tree[l++];
            if(~r & 1) ret += tree[r--];
        }
        return ret;
    }
};
bool flag = false;
void dnc(int s, int e, vector <int> &v, vector <int> &k, vector <int> &ans, vector <pll> &pt, SEG &ST) {
    if(s == e) return;
    int m = s + e >> 1;
    sort(all(v), [&](int a, int b) {
        if(pt[a].fi == pt[b].fi) return pt[a].se < pt[b].se;
        return pt[a].fi < pt[b].fi;
    });
    vector <int> upd, L, R;
    for(int i : v) {
        if(ans[i] > m) {
            int cnt = ST.cal(1, pt[i].se);
            if(flag) cnt = ST.cal(pt[i].se, pt[i].se);
            if(cnt >= k[i]) ans[i] = m;
            else k[i] -= cnt;
        }
        if(ans[i] <= m) {
            ST.update(pt[i].se, 1);
            upd.eb(pt[i].se);
            L.eb(i);
        }
        else R.eb(i);
    }
    for(int i : upd) ST.update(i, -1);
    dnc(s, m, L, k, ans, pt, ST);
    dnc(m+1, e, R, k, ans, pt, ST);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    ll x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    if(x1 * y2 - y1 * x2 < 0) swap(x1, x2), swap(y1, y2);
    if(x1 * y2 == y1 * x2) {
        flag = true;
        x2 = -y1, y2 = x1;
    }
    vector <int> k(n+1), ans(n+1), v;
    vector <ll> num;
    vector <pll> pt(n+1);
    for(int i = 1; i <= n; i++) {
        ll x, y; cin >> x >> y;
        pt[i].fi = y2 * x - x2 * y;
        pt[i].se = x1 * y - y1 * x;
        num.eb(pt[i].se);
    }
    sort(all(num));
    num.erase(unique(all(num)), num.end());
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        v.eb(i);
        pt[i].se = lower_bound(all(num), pt[i].se) - num.begin() + 1;
        ans[i] = i;
    }
    SEG ST(num.size());
    dnc(1, n, v, k, ans, pt, ST);
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}