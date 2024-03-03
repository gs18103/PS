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

struct Node {
    int rm = 0, lm = 0, s = 0, mx = 0;
};

int arr[MAX], in[MAX], hd[MAX], sz[MAX], p[MAX], dep[MAX], cnt, n;
Node tree[4*MAX];
int lazy[4*MAX];
vector <int> g[MAX];

void dfs(int x, int pa) {
    dep[x] = dep[pa] + 1;
    p[x] = pa;
    sz[x] = 1;
    for(int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if(y == pa) continue;
        dfs(y, x);
        sz[x] += sz[y];
        if(g[x][0] == pa || sz[y] > sz[g[x][0]]) {
            swap(g[x][i], g[x][0]);
        }
    }
}

void hld(int x) {
    in[x] = ++cnt;
    for(int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if(y == p[x]) continue;
        if(i == 0) hd[y] = hd[x];
        else hd[y] = y;
        hld(y);
    }
}

Node add(Node a, Node b) {
    Node ret;
    ret.s = a.s + b.s;
    ret.lm = max(a.lm, a.s + b.lm);
    ret.rm = max(b.rm, b.s + a.rm);
    ret.mx = max({a.mx, b.mx, a.rm + b.lm});
    return ret;
}

void update_lazy(int node, int s, int e) {
    if(lazy[node] != -INF) {
        if(s != e) {
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
        }
        tree[node].s = lazy[node] * (e - s + 1);
        tree[node].mx = max(0, tree[node].s);
        tree[node].rm = max(0, tree[node].s);
        tree[node].lm = max(0, tree[node].s);
        lazy[node] = -INF;
    }
}

void update(int node, int s, int e, int l, int r, int w) {
    update_lazy(node, s, e);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy[node] = w;
        update_lazy(node, s, e);
        return;
    }
    int m = (s + e) / 2;
    update(node*2, s, m, l, r, w);
    update(node*2+1, m+1, e, l, r, w);
    tree[node] = add(tree[node*2], tree[node*2+1]);
}

Node cal(int node, int s, int e, int l, int r) {
    update_lazy(node, s, e);
    Node ret;
    if(s > r || e < l) return ret;
    if(s >= l && e <= r) return tree[node];
    int m = (s + e) / 2;
    ret = add(cal(node*2, s, m, l, r), cal(node*2+1, m+1, e, l, r));
    return ret;
}

int max_query(int u, int v) {
    Node l, r;
    while(hd[u] != hd[v]) {
        if(dep[hd[u]] > dep[hd[v]]) {
            swap(l, r);
            swap(u, v);
        }
        r = add(cal(1, 1, n, in[hd[v]], in[v]), r);
        v = p[hd[v]];
    }
    if(dep[u] > dep[v]) {
        swap(u, v);
        swap(l, r);
    }
    r = add(cal(1, 1, n, in[u], in[v]), r);
    swap(l.rm, l.lm);
    return add(l, r).mx;
}

void update_query(int u, int v, int w) {
    while(hd[u] != hd[v]) {
        if(dep[hd[u]] > dep[hd[v]]) {
            swap(u, v);
        }
        update(1, 1, n, in[hd[v]], in[v], w);
        v = p[hd[v]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    update(1, 1, n, in[u], in[v], w);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    dfs(1, 0);
    hd[1] = 1;
    hld(1);

    for(int i = 1; i <= n; i++) {
        update(1, 1, n, in[i], in[i], arr[i]);
    }

    int q;
    cin >> q;
    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1) {
            cout << max_query(u, v) << '\n';
        }
        else {
            int w;
            cin >> w;
            update_query(u, v, w);  
        }
    }
}       