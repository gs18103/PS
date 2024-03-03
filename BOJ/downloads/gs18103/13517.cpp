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
const ll LINF = (ll)1e63;

int arr[MAX], root[MAX], p[20][MAX], dep[MAX];
vector <int> g[MAX];

struct Node {
    int l, r, val;
    Node(int L, int R, int Val) {
        l = L, r = R, val = Val;
    }
};

vector <Node> tree;

void expand_tree(int s, int e, int k, int cnd, int pnd) {
    if(s == e) {
        tree[cnd].val = tree[pnd].val + 1;
        return;
    }
    int m = (s + e) / 2;
    if(k <= m) {
        tree[cnd].r = tree[pnd].r;
        tree[cnd].l = tree.size();
        tree.eb(0, 0, 0);
        expand_tree(s, m, k, tree[cnd].l, tree[pnd].l);
    }
    else {
        tree[cnd].l = tree[pnd].l;
        tree[cnd].r = tree.size();
        tree.eb(0, 0, 0);
        expand_tree(m+1, e, k, tree[cnd].r, tree[pnd].r);
    }
    tree[cnd].val = tree[tree[cnd].l].val + tree[tree[cnd].r].val;
}

void dfs(int x, int pa) {
    dep[x] = dep[pa] + 1;
    p[0][x] = pa;
    for(int i = 1; i < 20; i++) {
        p[i][x] = p[i-1][p[i-1][x]];
    }
    root[x] = tree.size();
    tree.eb(0, 0, 0);
    expand_tree(1, 1000000, arr[x], root[x], root[pa]);
    for(auto i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
    }
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) {
        swap(u, v);
    }
    for(int i = 19; i >= 0; i--) {
        if(dep[v] - dep[u] >= (1 << i)) {
            v = p[i][v];
        }
    }
    if(u == v) return u;
    for(int i = 19; i >= 0; i--) {
        if(p[i][u] != p[i][v]) {
            u = p[i][u];
            v = p[i][v];
        }
    }
    return p[0][u];
}

int kth(int s, int e, int k, int cnd1, int cnd2, int pnd1, int pnd2) {
    if(s == e) return s;
    int lval = tree[tree[cnd1].l].val + tree[tree[cnd2].l].val - tree[tree[pnd1].l].val - tree[tree[pnd2].l].val;
    int m = (s + e) / 2;
    if(k <= lval) return kth(s, m, k, tree[cnd1].l, tree[cnd2].l, tree[pnd1].l, tree[pnd2].l);
    else return kth(m + 1, e, k - lval, tree[cnd1].r, tree[cnd2].r, tree[pnd1].r, tree[pnd2].r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    tree.eb(0, 0, 0);
    dfs(1, 0);

    int q;
    cin >> q;
    while(q--) {
        int u, v, k;
        cin >> u >> v >> k;
        int l = lca(u, v);
        cout << kth(1, 1000000, k, root[u], root[v], root[l], root[p[0][l]]) << '\n';
    }
}