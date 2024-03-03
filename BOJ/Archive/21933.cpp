#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

ll gcd(ll x, ll y) {
    if(!y) return x;
    return gcd(y, x % y);
}
ll lcm(ll x, ll y) {
    ll g = gcd(x, y);
    return g == 0 ? 0 : (x / g) * y;
}

ll g1, l1, g2, g3, g12, l12;

struct SegmentTree {
    struct Node {
        ll v1 = 0, v2 = 0, v3 = 0;
        Node operator + (const Node &X) {
            Node ret;
            g1 = gcd(v1, X.v1);
            l1 = (v1 / g1) * X.v1;
            g2 = gcd(v2, X.v2);
            g3 = gcd(v3, X.v3);
            g12 = gcd(l1, g2);
            l12 = (g12 == 0 ? 0 : (l1 / g12) * g2);

            ret.v1 = g1;
            ret.v2 = g12;
            ret.v3 = gcd(lcm(g12, g3), l12);
            return ret;
        }
        ll get(int x) {
            if(x == 0) return v1;
            if(x == 1) return v2;
            if(x == 2) return v3;
        }
    };
    vector <Node> tree;
    int sz;
    void Init(int n) {
        tree.resize(4*n+10);
        sz = n;
    }
    void update(int k, int val) {
        update(1, 1, sz, k, val);
    }
    void update(int node, int s, int e, int k, int val) {
        if(s == e) {
            tree[node].v1 = val;
            return;
        }
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, val);
        else update(node<<1|1, m+1, e, k, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
    Node cal(int l, int r) {
        return cal(1, 1, sz, l, r);
    }
    Node cal(int node, int s, int e, int l, int r) {
        if(s >= l && e <= r) return tree[node];
        int m = s + e >> 1;
        if(r <= m) return cal(node<<1, s, m, l, r);
        else if(m < l) return cal(node<<1|1, m+1, e, l, r);
        else return cal(node<<1, s, m, l, r) + cal(node<<1|1, m+1, e, l, r);
    }
    void traverse() {Traverse(1, 1, sz);}
    void Traverse(int node, int s, int e) {
        if(s == e) return;
        int m = s + e >> 1;
        Traverse(node<<1, s, m);
        Traverse(node<<1|1, m+1, e);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    SegmentTree ST;
    ST.Init(n);
    for(int i = 1; i <= n; i++) {
        int v; cin >> v;
        ST.update(i, v);
    }
    ST.traverse();
    while(q--) {
        string s;
        cin >> s;
        if(s == "Q") {
            int l, r, k;
            cin >> l >> r >> k;
            cout << ST.cal(l, r).get(k) << '\n';
        }
        else {
            int j, x;
            cin >> j >> x;
            ST.update(j, x);
        }
    }
}