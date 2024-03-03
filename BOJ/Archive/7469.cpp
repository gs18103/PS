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

const int INF = 1 << 30;
const ll LINF = 1LL << 62;
const int MAX = 101010;

struct Node {
    int l, r, val;
    Node(int l, int r, int val) : l(l), r(r), val(val) {};
};

int a[MAX], root[MAX];
vector <int> num;
vector <Node> tree;

void expand_tree(int s, int e, int k, int val, int pnd, int cnd) {
    if(s == e) {
        tree[cnd].val = tree[pnd].val + val;
        return;
    }
    int m = (s + e) / 2;
    if(k <= m) {
        tree[cnd].l = tree.size();
        tree[cnd].r = tree[pnd].r;
        tree.eb(0, 0, 0);
        expand_tree(s, m, k, val, tree[pnd].l, tree[cnd].l);
    }
    else {
        tree[cnd].l = tree[pnd].l;
        tree[cnd].r = tree.size();
        tree.eb(0, 0, 0);
        expand_tree(m+1, e, k, val, tree[pnd].r, tree[cnd].r);
    }
    tree[cnd].val = tree[tree[cnd].l].val + tree[tree[cnd].r].val;
}

int get_kth(int s, int e, int pnd, int cnd, int k) {
    if(s == e) return num[s-1];
    int m = (s + e) / 2;
    int lval = tree[tree[cnd].l].val - tree[tree[pnd].l].val;
    if(lval >= k) return get_kth(s, m, tree[pnd].l, tree[cnd].l, k);
    else return get_kth(m+1, e, tree[pnd].r, tree[cnd].r, k - lval);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        num.eb(a[i]);
    }
    sort(all(num));
    tree.eb(0, 0, 0);
    for(int i = 1; i <= n; i++) {
        a[i] = lower_bound(all(num), a[i]) - num.begin() + 1;
        root[i] = tree.size();
        tree.eb(0, 0, 0);
        expand_tree(1, n, a[i], 1, root[i-1], root[i]);
    }

    while(q--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << get_kth(1, n, root[i-1], root[j], k) << '\n';
    }
}