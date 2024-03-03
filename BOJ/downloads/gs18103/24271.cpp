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

struct SegmentTree {
    vector <int> tree;
    int sz, lg;
    void Init(int n) {
        sz = 1; lg = 0;
        while(sz <= n) sz <<= 1, lg++;
        tree.resize(sz<<1);
    }

    void update(int k, int x) {
        update(1, 0, sz-1, k, x);
    }
    void update(int node, int s, int e, int k, int x) {
        if(s == e) {
            tree[node] ^= x;
            return;
        }
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, x);
        else update(node<<1|1, m+1, e, k, x);
        tree[node] = tree[node<<1] ^ tree[node<<1|1];
    }

    int cal(int l, int r, int x) {
        return cal(1, 0, sz-1, l, r, x, lg - 1);
    }
    int cal(int node, int s, int e, int l, int r, int x, int b) {
        if(s == l && e == r) return tree[node];
        int m = s + e >> 1;
        if(x >> b & 1) {
            if(l > m) return cal(node<<1, s, m, l - (1 << b), r - (1 << b), x, b-1);
            else if(r <= m) return cal(node<<1|1, m+1, e, l + (1 << b), r + (1 << b), x, b-1);
            else return cal(node<<1, s, m, s, r - (1 << b), x, b-1) ^ cal(node<<1|1, m+1, e, l + (1 << b), e, x, b-1);
        }
        else {
            if(l > m) return cal(node<<1|1, m+1, e, l, r, x, b-1);
            else if(r <= m) return cal(node<<1, s, m, l, r, x, b-1);
            else return cal(node<<1, s, m, l, m, x, b-1) ^ cal(node<<1|1, m+1, e, m+1, r, x, b-1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    SegmentTree ST;
    ST.Init(n);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ST.update(i, a);
    }

    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 2) {
            int i, x;
            cin >> i >> x;
            ST.update(i, x);
        }
        if(t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            cout << ST.cal(l, r, x) << '\n';
        }
    }
}