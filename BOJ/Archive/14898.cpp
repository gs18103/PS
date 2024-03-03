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

const int MAX = 1010101;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

struct PersistentSegmentTree {
    struct Node {
        int l, r, val;
        Node(int l, int r, int val) : l(l), r(r), val(val) {}
    };
    vector <Node> tree;
    vector <int> root;

    void Init(int n) {
        tree.eb(0, 0, 0);
        root.eb(0);
    }

    void update(int cnd, int pnd, int k, int s = 0, int e = MAX) {
        tree[cnd].val = tree[pnd].val + 1;
        if(s == e) return;
        int m = (s + e) / 2;
        if(k <= m) {
            tree[cnd].r = tree[pnd].r;
            tree[cnd].l = tree.size();
            tree.eb(0, 0, 0);
            update(tree[cnd].l, tree[pnd].l, k, s, m);
        }
        else {
            tree[cnd].l = tree[pnd].l;
            tree[cnd].r = tree.size();
            tree.eb(0, 0, 0);
            update(tree[cnd].r, tree[pnd].r, k, m+1, e);
        }
    }

    void add(int k) {
        root.eb(tree.size());
        tree.eb(0, 0, 0);
        update(root[root.size()-1], root[root.size()-2], k);
    }

    int cal(int cnd, int l, int r, int s = 0, int e = MAX) {
        if(s > r || e < l) return 0;
        if(s >= l && e <= r) return tree[cnd].val;
        int m = (s + e) / 2;
        return cal(tree[cnd].l, l, r, s, m) + cal(tree[cnd].r, l, r, m+1, e);
    }

} PST;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    map <int, int> mp;
    cin >> n;
    PST.Init(n);
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        PST.add(mp[k]);
        mp[k] = i;
    }

    int q, ans = 0;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l += ans;
        ans = PST.cal(PST.root[r], 0, l - 1) - l + 1;
        cout << ans << '\n';
    }
}