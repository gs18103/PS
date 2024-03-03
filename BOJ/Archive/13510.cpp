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

vector <pii> g[MAX];
int n;
int sz[MAX], in[MAX], nxt[MAX], p[MAX], dep[MAX], val[MAX], po[MAX], cnt;
int tree[4*MAX];

void dfs(int x, int pa) {
    sz[x] = 1;
    p[x] = pa;
    dep[x] = dep[pa] + 1;
    for(int i = 0; i < g[x].size(); i++) {
        int y = g[x][i].fi;
        if(y == pa) continue;
        dfs(y, x);
        sz[x] += sz[y];
        po[g[x][i].se] = y;
        if(sz[y] > sz[g[x][0].fi] || g[x][0].fi == pa) {
            swap(g[x][i], g[x][0]);
        }
    }
}

void hld(int x) {
    in[x] = ++cnt;
    for(int i = 0; i < g[x].size(); i++) {
        int y = g[x][i].fi;
        if(y == p[x]) continue;
        if(i == 0) nxt[y] = nxt[x];
        else nxt[y] = y;
        hld(y);
    }
}

void update(int node, int s, int e, int k, int x) {
    if(s == e) {
        tree[node] = x;
        return;
    }
    int m = (s + e) / 2;
    if(k <= m) update(node * 2, s, m, k, x);
    else update(node * 2 + 1, m + 1, e, k, x);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int cal(int node, int s, int e, int l, int r) {
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[node];
    int m = (s + e) / 2;
    int ret = max(cal(node * 2, s, m, l, r), cal(node * 2 + 1, m + 1, e, l, r));
    return ret;
}

int maxquery(int u, int v) {
    int ret = 0;
    while(nxt[u] != nxt[v]) {
        if(dep[nxt[u]] > dep[nxt[v]]) swap(u, v);
        ret = max(ret, cal(1, 1, n, in[nxt[v]], in[v]));
        v = p[nxt[v]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    if(u != v) ret = max(ret, cal(1, 1, n, in[u] + 1, in[v]));
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, i);
        g[v].eb(u, i);
        val[i] = w;
    }
    dfs(1, 0);
    nxt[1] = 1;
    hld(1);
    for(int i = 1; i < n; i++) {
        update(1, 1, n, in[po[i]], val[i]);
    }

    int q;
    cin >> q;
    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1) {
            val[u] = v;
            update(1, 1, n, in[po[u]], v);
        }
        if(t == 2) {
            cout << maxquery(u, v) << '\n';
        }
    }
}