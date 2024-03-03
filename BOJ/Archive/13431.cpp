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

vector <pii> g[MAX];
map <int, ll> sub[MAX];

int sz[MAX], crt, ctp[MAX], p[20][MAX], dep[MAX], n, c[MAX];
ll d[20][MAX], sum[MAX], cnt[MAX];
bool chk[MAX];

void dfs(int x, int pa) {
    sz[x] = 1;
    p[0][x] = pa;
    dep[x] = dep[pa] + 1;
    for(int i = 1; i <= 17; i++) {
        p[i][x] = p[i-1][p[i-1][x]];
        d[i][x] = d[i-1][x] + d[i-1][p[i-1][x]];
    }
    for(auto i : g[x]) {
        if(i.fi == pa) continue;
        d[0][i.fi] = i.se;
        dfs(i.fi, x);
        sz[x] += sz[i.fi];
    }
}

ll dist(int u, int v) {
    ll ret = 0;
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 17; i >= 0; i--) {
        if(dep[v] - dep[u] >= (1 << i)) {
            ret += d[i][v];
            v = p[i][v];
        }
    }
    if(u == v) return ret;
    for(int i = 17; i >= 0; i--) {
        if(p[i][u] != p[i][v]) {
            ret += d[i][u] + d[i][v];
            u = p[i][u];
            v = p[i][v];
        }
    }
    return ret + d[0][u] + d[0][v];
}

int find_cen(int x) {
    int csz = 1, mx = 0, y = 0;
    for(auto i : g[x]) { 
        if(chk[i.fi]) continue;
        csz += sz[i.fi];
        if(sz[i.fi] > mx) {
            mx = sz[i.fi];
            y = i.fi;
        }
    }
    if(mx <= csz / 2) return x;
    sz[x] = csz - mx;
    return find_cen(y);
}

int make_ct(int x) {
    x = find_cen(x);
    chk[x] = true;
    for(int i = 0; i < g[x].size(); i++) {
        if(chk[g[x][i].fi]) continue;
        ctp[make_ct(g[x][i].fi)] = x;
    }
    return x;
}

void update(int v) {
    if(c[v]) return;
    c[v] = 1;
    cnt[v]++;
    int x = ctp[v];
    int pre = v;
    while(x != 0) {
        ll temp = dist(x, v);
        sum[x] += temp;
        sub[x][pre] += temp;
        cnt[x]++;
        pre = x;
        x = ctp[x];
    }
}

ll query(int v) {
    int precnt = cnt[v];
    ll ret = sum[v];
    int x = ctp[v];
    int pre = v;
    while(x != 0) {
        ll temp = dist(x, v);
        ret += temp * (cnt[x] - precnt) + sum[x] - sub[x][pre];
        precnt = cnt[x];
        pre = x;
        x = ctp[x];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u++;
        v++;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    dfs(1, 0);
    crt = make_ct(1);

    while(q--) {
        int t, v;
        cin >> t >> v;
        v++;
        if(t == 1) {
            update(v);
        }
        else cout << query(v) << '\n';
    }
}