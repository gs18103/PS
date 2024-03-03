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

const int MAX = 505050;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

int root[MAX], a[MAX], r[MAX], n;

struct Node {
    int l, r, val;
    Node(int l, int r, int val) : l(l), r(r), val(val) {}
};

vector <Node> tree;

void expand_tree(int cnd, int pnd, int s, int e, int k) {
    tree[cnd].val = tree[pnd].val + 1;
    if(s == e) return;
    int m = s + e >> 1;
    if(k <= m) {
        tree[cnd].l = tree.size();
        tree[cnd].r = tree[pnd].r;
        tree.eb(0, 0, 0);
        expand_tree(tree[cnd].l, tree[pnd].l, s, m, k);
    }
    else {
        tree[cnd].r = tree.size();
        tree[cnd].l = tree[pnd].l;
        tree.eb(0, 0, 0);
        expand_tree(tree[cnd].r, tree[pnd].r, m+1, e, k);
    }
}

int get_mid(int cnd, int pnd, int s, int e, int k) {
    if(s == e) return s;
    int cnt = tree[tree[cnd].l].val - tree[tree[pnd].l].val;
    int m = s + e >> 1;
    if(cnt >= k) return get_mid(tree[cnd].l, tree[pnd].l, s, m, k);
    else return get_mid(tree[cnd].r, tree[pnd].r, m+1, e, k - cnt);
}

ll get_ans(int l, int r) {
    if(l >= r) return 0;
    int pivot = a[get_mid(root[r], root[l-1], 0, n - 1, (r - l + 2) / 2)];
    return get_ans(l, pivot - 1) + get_ans(pivot + 1, r) + r - l + 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        r[a[i]] = i;
    }

    tree.eb(0, 0, 0);
    for(int i = 1; i <= n; i++) {
        root[i] = tree.size();
        tree.eb(0, 0, 0);
        expand_tree(root[i], root[i-1], 0, n - 1, r[i]);
    }

    cout << get_ans(1, n);
}