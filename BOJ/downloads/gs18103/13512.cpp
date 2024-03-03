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
const ll LINF = (ll)1e18;

int n;
int in[MAX], dep[MAX], p[MAX], hd[MAX], sz[MAX], cnt, invin[MAX];
vector <int> g[MAX];
int tree[4*MAX];

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
            swap(g[x][0], g[x][i]);
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

void init(int node, int s, int e) {
    tree[node] = INF;
    if(s == e) return;
    int m = (s + e) / 2;
    init(node * 2, s, m);
    init(node * 2 + 1, m + 1, e);
}

void update(int node, int s, int e, int k) {
    if(s == e) {
        if(tree[node] == INF) tree[node] = s;
        else tree[node] = INF;
        return;
    }
    int m = (s + e) / 2;
    if(k <= m) update(node * 2, s, m, k);
    else update(node * 2 + 1, m + 1, e, k);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int cal(int node, int s, int e, int l, int r) {
    if(s > r || e < l) return INF;
    if(s >= l && e <= r) return tree[node];
    int m = (s + e) / 2;
    return min(cal(node * 2, s, m, l, r), cal(node * 2 + 1, m + 1, e, l, r));
}

int query_min(int u, int v) {
    int ret = INF;
    while(hd[u] != hd[v]) {
        if(dep[hd[u]] > dep[hd[v]]) swap(u, v);
        ret = min(ret, cal(1, 1, n, in[hd[v]], in[v]));
        v = p[hd[v]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    ret = min(ret, cal(1, 1, n, in[u], in[v]));
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }

    dfs(1, 0);
    hd[1] = 1;
    hld(1);

    init(1, 1, n);

    for(int i = 1; i <= n; i++) {
        invin[in[i]] = i;
    }

    int q;
    cin >> q;
    while(q--) {
        int t, v;
        cin >> t >> v;
        if(t == 1) {
            update(1, 1, n, in[v]);
        }
        else {
            int val = query_min(1, v);
            cout << (val == INF ? -1 : invin[val]) << '\n';
        }
    }
}