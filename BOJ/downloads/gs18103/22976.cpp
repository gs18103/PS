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

const int MAX = 2020;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll mod = 1e9+7;

class SegmentTree {
    vector <pll> tree;
    int sz;
public:
    void Init(vector <pll> &A) {
        sz = A.size();
        tree.resize(4*sz+10);
        init(1, 1, sz, A);
    }
    void init(int node, int s, int e, vector <pll> &A) {
        if(s == e) {
            tree[node] = A[s-1];
            //cout << s << ' ' << e << ' ' << tree[node].fi << ' ' << tree[node].se << endl;
            return;
        }
        int m = s + e >> 1;
        init(node<<1, s, m, A);
        init(node<<1|1, m+1, e, A);
        tree[node].fi = (tree[node<<1].fi * tree[node<<1|1].fi) % mod;
        tree[node].se = (tree[node<<1].se * tree[node<<1|1].fi + tree[node<<1|1].se) % mod;
        //cout << s << ' ' << e << ' ' << tree[node].fi << ' ' << tree[node].se << endl;
    }

    void update(int node, int s, int e, int k, pll val) {
        if(s == e) {
            tree[node] = val;
            return;
        }
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, val);
        else update(node<<1|1, m+1, e, k, val);
        tree[node].fi = (tree[node<<1].fi * tree[node<<1|1].fi) % mod;
        tree[node].se = (tree[node<<1].se * tree[node<<1|1].fi + tree[node<<1|1].se) % mod;
    }

    ll ans() {
        return tree[1].se;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector <pll> A(n);
    for(int i = 0; i < n; i++) {
        string s; int u;
        cin >> s >> u;
        if(s == "+") A[i] = {1, u};
        else A[i] = {u, 0};
    }
    SegmentTree ST;
    ST.Init(A);
    
    while(q--) {
        int idx, u;
        string s;
        cin >> idx >> s >> u;
        if(s == "+") {
            ST.update(1, 1, n, idx, {1, u});
        }
        else {
            ST.update(1, 1, n, idx, {u, 0});
        }
        cout << ST.ans() << '\n';
    }
}