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
const int INF = 1e9;
const ll LINF = 1e18;

class SegmentTree {
    struct Node {
        ll sum, mn, mx;
        Node(ll sum = 0, ll mn = LINF, ll mx = -LINF) : sum(sum), mn(mn), mx(mx) {}
        Node operator + (Node b) {
            Node ret;
            ret.sum = sum + b.sum;
            ret.mx = max(mx, b.mx);
            ret.mn = min(mn, b.mn);
            return ret;
        }
    };
    vector <Node> tree;
    vector <pll> lazy;
    int n;

public:

    ll div(ll a, ll d) {
        if(a >= 0) return a / d;
        else return (a - (d - 1)) / d;
    }

    
    void update_lazy(int node, int s, int e) {
        tree[node].sum = tree[node].sum * lazy[node].fi + lazy[node].se * (e-s+1);
        tree[node].mx = tree[node].mx * lazy[node].fi + lazy[node].se;
        tree[node].mn = tree[node].mn * lazy[node].fi + lazy[node].se;
        if(s != e) {
            lazy[node<<1].fi = lazy[node<<1].fi * lazy[node].fi;
            lazy[node<<1].se = lazy[node<<1].se * lazy[node].fi + lazy[node].se;
            lazy[node<<1|1].fi = lazy[node<<1|1].fi * lazy[node].fi;
            lazy[node<<1|1].se = lazy[node<<1|1].se * lazy[node].fi + lazy[node].se;
        }
        lazy[node] = {1, 0};
    }

    void Init(int N, vector <ll> &A) {
        n = N;
        tree.resize(4*n+10);
        lazy.resize(4*n+10);
        init(1, 0, n-1, A);
    }

    void init(int node, int s, int e, vector <ll> &A) {
        lazy[node] = {1, 0};
        if(s == e) {
            tree[node].sum = tree[node].mn = tree[node].mx = A[s];
            return;
        }
        int m = s + e >> 1;
        init(node<<1, s, m, A);
        init(node<<1|1, m+1, e, A);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    void divide(int l, int r, ll d) {
        update_d(1, 0, n-1, l, r, d);
    }

    void update_d(int node, int s, int e, int l, int r, ll d) {
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r && div(tree[node].mx, d) == div(tree[node].mn, d)) {
            lazy[node].fi = 0;
            lazy[node].se = div(tree[node].mx, d);
            update_lazy(node, s, e);
            return;
        }
        if(s >= l && e <= r && tree[node].mx - tree[node].mn == 1) {
            lazy[node].se = div(tree[node].mn, d) - tree[node].mn;
            update_lazy(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update_d(node<<1, s, m, l, r, d);
        update_d(node<<1|1, m+1, e, l, r, d);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
    
    void add(int l, int r, ll s) {
        update_s(1, 0, n-1, l, r, s);
    }

    void update_s(int node, int s, int e, int l, int r, ll c) {
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            lazy[node].se = c;
            update_lazy(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update_s(node<<1, s, m, l, r, c);
        update_s(node<<1|1, m+1, e, l, r, c);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    ll sum(int l, int r) {
        return cal(1, 0, n-1, l, r).sum;
    }

    ll mx(int l, int r) {
        return cal(1, 0, n-1, l, r).mx;
    }

    Node cal(int node, int s, int e, int l, int r) {
        update_lazy(node, s, e);
        if(s > r || e < l) return Node();
        if(s >= l && e <= r) return tree[node];
        int m = s + e >> 1;
        return cal(node<<1, s, m, l, r) + cal(node<<1|1, m+1, e, l, r);
    }
} ST;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector <ll> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ST.Init(n, A);

    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 0) {
            ll c;
            cin >> c;
            ST.add(l, r, c);
        }
        if(t == 1) {
            ll d;
            cin >> d;
            ST.divide(l, r, d);
        }
        if(t == 2) {
            ll c;
            cin >> c;
            cout << ST.mx(l, r) << '\n';
        }
    }
}