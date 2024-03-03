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

vector <int> g[MAX];
multiset <int> st[MAX];

int sz[MAX], crt, ctp[MAX], p[20][MAX], dep[MAX], c[MAX];
bool chk[MAX];

void dfs(int x, int pa) {
    sz[x] = 1;
    p[0][x] = pa;
    dep[x] = dep[pa] + 1;
    for(int i = 1; i <= 17; i++) {
        p[i][x] = p[i-1][p[i-1][x]];
    }
    for(auto i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
        sz[x] += sz[i];
    }
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 17; i >= 0; i--) {
        if(dep[v] - dep[u] >= (1 << i)) {
            v = p[i][v];
        }
    }
    if(u == v) return u;
    for(int i = 17; i >= 0; i--) {
        if(p[i][u] != p[i][v]) {
            u = p[i][u];
            v = p[i][v];
        }
    }
    return p[0][u];
}

int dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int find_cen(int x) {
    int csz = 1, mx = 0, y = 0;
    for(auto i : g[x]) { 
        if(chk[i]) continue;
        csz += sz[i];
        if(sz[i] > mx) {
            mx = sz[i];
            y = i;
        }
    }
    if(mx <= csz / 2) return x;
    sz[x] = csz - mx;
    return find_cen(y);
}

int make_ct(int x) {
    x = find_cen(x);
    chk[x] = true;
    for(auto i : g[x]) {
        if(chk[i]) continue;
        ctp[make_ct(i)] = x;
    }
    return x;
}

void update(int v, int x) {
    int d = dist(v, x);
    if(c[v] == 1) st[x].em(d);
    else st[x].erase(st[x].find(d));
    if(x == crt) return;
    update(v, ctp[x]);
}

int query_min(int v, int x) {
    int ret;
    if(st[x].empty()) ret = INF;
    else ret = dist(v, x) + (*st[x].begin());
    if(x == crt) return ret;
    return min(ret, query_min(v, ctp[x]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    dfs(1, 0);
    crt = make_ct(1);

    int q;
    cin >> q;
    while(q--) {
        int t, v;
        cin >> t >> v;
        if(t == 1) {
            c[v] = (c[v] + 1) % 2;
            update(v, v);
        }
        else {
            int val = query_min(v, v);
            cout << (val == INF ? -1 : val) << '\n';
        }
    }
}