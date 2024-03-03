#include <bits/stdc++.h>

using namespace std;

struct SEG {
    vector <int> tree;
    int sz;
    SEG(int n) :sz(n) {
        tree.resize(4*n+10);
    }

    void update(int x, int val) {
        update(1, 1, sz, x, val);
    }
    void update(int node, int s, int e, int k, int val) {
        if(s == e) {
            tree[node] += val;
            return;
        }
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, val);
        else update(node<<1|1, m+1, e, k, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    int kth(int x) {
        int ret = kth(1, 1, sz, x);
        update(ret, -1);
        return ret;
    }
    int kth(int node, int s, int e, int k) {
        if(s == e) return s;
        int m = s + e >> 1;
        if(tree[node<<1] >= k) return kth(node<<1, s, m, k);
        else return kth(node<<1|1, m+1, e, k - tree[node<<1]);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int q;
    cin >> q;
    SEG ST(2'000'000);
    while(q--) {
        int t, x;
        cin >> t >> x;
        if(t == 1) ST.update(x, 1);
        if(t == 2) cout << ST.kth(x) << '\n';
    }
}