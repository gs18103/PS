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

const int MAX = 101010;
const int INF = (int)1e9;
const ll LINF = (ll)9e18;

class SegmentTree {
public:
    struct Node {
        ll l = -LINF, r = -LINF;
        int lmx = 1, rmx = 1, mx = 1;
        bool s = false;
        Node operator + (Node b) {
            Node ret;
            if(l == -LINF) return b;
            if(b.l == -LINF) {
                ret.l = l;
                ret.r = r;
                ret.lmx = lmx;
                ret.rmx = rmx;
                ret.mx = mx;
                ret.s = s;
                return ret;
            }
            ret.l = l;
            ret.r = b.r;
            if(s && b.s && l == b.l) ret.s = true;
            if(s && l == b.l) ret.lmx = lmx + b.lmx;
            else ret.lmx = lmx;
            if(b.s && r == b.r) ret.rmx = rmx + b.rmx;
            else ret.rmx = b.rmx;
            ret.mx = max(mx, b.mx);
            if(r == b.l) ret.mx = max(ret.mx, rmx + b.lmx);
            return ret;
        }
    };
    vector <Node> tree;
    vector <ll> lazy;
    int sz;

    void Init(int n, vector <ll> &A) {
        sz = n;
        tree.resize(4*n+10);
        lazy.resize(4*n+10);
        init(1, n, A);
    }

    void init(int s, int e, vector <ll> &A, int node = 1) {
        if(s == e) {
            tree[node].l = tree[node].r = A[s];
            tree[node].lmx = tree[node].rmx = tree[node].mx = 1;
            tree[node].s = true;
            return;
        }
        int m = s + e >> 1;
        init(s, m, A, node<<1);
        init(m + 1, e, A, node<<1|1);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    void update_lazy(int node, int s, int e) {
        tree[node].l += lazy[node];
        tree[node].r += lazy[node];
        if(s != e) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }

    Node Cal(int l, int r) {
        return cal(1, sz, l, r);
    }

    Node cal(int s, int e, int l, int r, int node = 1) {
        update_lazy(node, s, e);
        Node ret;
        if(s > r || e < l) return ret;
        if(s >= l && e <= r) return tree[node];
        int m = s + e >> 1;
        ret = cal(s, m, l, r, node<<1) + cal(m + 1, e, l, r, node<<1|1);
        return ret;
    }

    void Update(int l, int r, ll val) {
        update(1, sz, l, r, val);
    }

    void update(int s, int e, int l, int r, ll val, int node = 1) {
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            lazy[node] += val;
            update_lazy(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update(s, m, l, r, val, node<<1);
        update(m+1, e, l, r, val, node<<1|1);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
} ST;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <ll> A(n+1), D(n);
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for(int i = 1; i < n; i++) {
        D[i] = A[i+1] - A[i];
    }
    ST.Init(n - 1, D);

    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int i, j;
            ll x, y;
            cin >> i >> j >> x >> y;
            if(i > 1) ST.Update(i - 1, i - 1, x);
            if(j > i) ST.Update(i, j - 1, y);
            if(j < n) ST.Update(j, j, - x - y * (j - i));
        }
        else {
            int i, j;
            cin >> i >> j;
            cout << ST.Cal(i, j - 1).mx + 1 << '\n';
        }
    }
}