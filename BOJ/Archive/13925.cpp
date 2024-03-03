#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const ll mod = 1e9+7;

ll tree[4*MAX];
pll lazy[4*MAX];

void update_lazy(int node, int s, int e) {
    tree[node] = (tree[node] * lazy[node].fi + (e-s+1) * lazy[node].se) % mod;
    if(s != e) {
        lazy[node<<1].fi = (lazy[node<<1].fi * lazy[node].fi) % mod;
        lazy[node<<1].se = (lazy[node<<1].se * lazy[node].fi + lazy[node].se) % mod;
        lazy[node<<1|1].fi = (lazy[node<<1|1].fi * lazy[node].fi) % mod;
        lazy[node<<1|1].se = (lazy[node<<1|1].se * lazy[node].fi + lazy[node].se) % mod;
    }
    lazy[node] = make_pair(1, 0);
}

void update(int node, int s, int e, int l, int r, ll a, ll b) {
    update_lazy(node, s, e);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[node].fi = (lazy[node].fi * a) % mod;
        lazy[node].se = (lazy[node].se * a + b) % mod;
        update_lazy(node, s, e);
        return;
    }
    int m = (s + e) >> 1;
    update(node<<1, s, m, l, r, a, b), update(node<<1|1, m+1, e, l, r, a, b);
    tree[node] = (tree[node<<1] + tree[node<<1|1]) % mod;
}

ll cal(int node, int s, int e, int l, int r) {
    update_lazy(node, s, e);
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[node] % mod;
    int m = (s + e) >> 1;
    return (cal(node<<1, s, m, l, r) + cal(node<<1|1, m+1, e, l, r)) % mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ll u; cin >> u;
        update(1, 1, n, i, i, 0, u);
    }
    for(int i = 1; i < 4 * MAX; i++) {
        lazy[i] = make_pair(1, 0);
    }
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, y, v;
            cin >> x >> y >> v;
            update(1, 1, n, x, y, 1, v);
        }
        if(t == 2) {
            int x, y, v;
            cin >> x >> y >> v;
            update(1, 1, n, x, y, v, 0);
        }
        if(t == 3) {
            int x, y, v;
            cin >> x >> y >> v;
            update(1, 1, n, x, y, 0, v);
        }
        if(t == 4) {
            int x, y;
            cin >> x >> y;
            cout << cal(1, 1, n, x, y) << '\n';
        }
    }
}