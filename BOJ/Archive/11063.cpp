#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef pair <int, int> pii;

const int INF = 1e9;

struct SEG {
    vector <pii> tree;
    int sz;
    bool base;
    SEG(int n, bool _base = true) : base(_base) {
        for(sz = 1; sz < n; sz <<= 1) {}
        tree.resize(sz<<1);
        for(auto &i : tree) i = pii(0, INF);
    }

    void update(int k, int val) {
        int node = sz + k - base;
        tree[node].fi = max(tree[node].fi, val);
        tree[node].se = min(tree[node].se, val);
        while(node >>= 1) {
            tree[node].fi = max(tree[node<<1].fi, tree[node<<1|1].fi);
            tree[node].se = min(tree[node<<1].se, tree[node<<1|1].se);
        }
    }
    int cal(int l, int r) {
        pii ret = pii(0, INF);
        for(l += sz - base, r += sz - base; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) {
                ret.fi = max(ret.fi, tree[l].fi);
                ret.se = min(ret.se, tree[l].se);
                l++;
            }
            if(~r & 1) {
                ret.fi = max(ret.fi, tree[r].fi);
                ret.se = min(ret.se, tree[r].se);
                r--;
            }
        }
        return ret.fi - ret.se;
    }
};

void solve() {
    int n, l;
    cin >> n >> l;
    vector <int> L(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> L[i];
    }
    SEG ST(n);
    for(int i = 1; i <= n; i++) {
        int v; cin >> v;
        ST.update(v, i);
    }
    int lb = 1, ub = 1;
    for(int i = 1; i <= n; i++) {
        while(L[lb] + l < L[i]) lb++;
        while(ub + 1 <= n && L[i] + l >= L[ub+1]) ub++;
        if(ST.cal(lb, ub) != ub - lb) {
            cout << "-1\n";
            return;
        }
    }
    cout << "1\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}