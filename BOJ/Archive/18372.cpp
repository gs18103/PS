#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

int sz[MAX], p[18][MAX], in_ct[20][MAX], d_ct[18][MAX], dep[MAX], rt;
bool chk[MAX], nchk[MAX];
vector <int> g[MAX];
vector <int> dcnt[MAX], dcnt_tot[MAX];

void dfs(int x, int pa) {
    sz[x] = 1;
    p[0][x] = pa;
    dep[x] = dep[pa] + 1;
    for(int i = 1; i < 18; i++) {
        p[i][x] = p[i-1][p[i-1][x]];
    }
    for(int i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
        sz[x] += sz[i];
    }
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

void ndfs(int x, int &pa, int &cen, int &y, int &lv, int d) {
    in_ct[lv][x] = y;
    d_ct[lv][x] = d;
    if(dcnt[y].size() == d) dcnt[y].eb(0);
    if(dcnt_tot[cen].size() == d) dcnt_tot[cen].eb(0);
    if(x & 1) {
        dcnt[y][d]++;
        dcnt_tot[cen][d]++;
    }
    for(int i : g[x]) {
        if(chk[i] || i == pa) continue;
        ndfs(i, x, cen, y, lv, d + 1);
    }
}

int make_ct(int x, int lv = 0) {
    x = find_cen(x);
    chk[x] = true;
    dcnt_tot[x].eb(x & 1);
    for(auto i : g[x]) {
        if(chk[i]) continue;
        int y = make_ct(i, lv + 1);
        dcnt[y].eb(0);
        ndfs(i, x, x, y, lv, 1);
        for(int j = 1; j < dcnt[y].size(); j++) {
            dcnt[y][j] += dcnt[y][j-1];
        }
    }
    for(int j = 1; j < dcnt_tot[x].size(); j++) {
        dcnt_tot[x][j] += dcnt_tot[x][j-1];
    }
    chk[x] = false;
    return x;
}

int query(int x, pii val, int lv = 0) {
    if(x == val.fi) return dcnt_tot[x][min((int)dcnt_tot[x].size()-1, val.se)];
    int y = in_ct[lv][val.fi];
    int ans = 0, td = val.se - d_ct[lv][val.fi];
    if(td >= 0) {
        ans = dcnt_tot[x][min((int)dcnt_tot[x].size()-1,td)]
                 - dcnt[y][min((int)dcnt[y].size()-1, td)];
    }
    return ans + query(y, val, lv + 1);
}
int query(pii val) {
    if(val.se < 0) return 0;
    return query(rt, val);
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 17; i >= 0; i--) {
        if(dep[u] - dep[v] >= (1 << i)) u = p[i][u];
    }
    if(u == v) return u;
    for(int i = 17; i >= 0; i--) {
        if(p[i][u] != p[i][v]) u = p[i][u], v = p[i][v];
    }
    return p[0][u];
}

int kth(int x, int k) {
    for(int i = 0; i < 18; i++) {
        if(k >> i & 1) x = p[i][x];
    }
    return x;
}

pii merge(pii x, pii y) {
    int l = lca(x.fi, y.fi);
    int dist = dep[x.fi] + dep[y.fi] - 2 * dep[l];
    if(dist + x.se <= y.se) return x;
    if(dist + y.se <= x.se) return y;
    if(y.se + x.se < dist) return pii(x.fi, -INF);
    int xd = (x.se + dist - y.se) / 2;
    int cen;
    if(xd <= dep[x.fi] - dep[l]) cen = kth(x.fi, xd);
    else cen = kth(y.fi, dist - xd);
    return pii(cen, (x.se + y.se - dist) / 2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u = 2 * u - 1, v = 2 * v - 1;
        g[u].eb(2*i);
        g[2*i].eb(u);
        g[2*i].eb(v);
        g[v].eb(2*i);
    }
    
    dfs(1, 0);
    rt = make_ct(1);
    
    int q;
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        vector <pii> v(k), L(k), R(k);
        for(int i = 0; i < k; i++) {
            cin >> v[i].fi >> v[i].se;
            v[i].fi = 2 * v[i].fi - 1;
            v[i].se *= 2;
        }
        if(k == 1) {
            cout << n << '\n';
            continue;
        }
        L[0] = v[0], R[k-1] = v[k-1];
        for(int i = 1; i < k; i++) {
            L[i] = merge(L[i-1], v[i]);
            R[k-i-1] = merge(R[k-i], v[k-i-1]);
        }
        ll ans = query(L[k-2]) + query(R[1]);
        for(int i = 1; i + 1 < k; i++) {
            ans += query(merge(L[i-1], R[i+1]));
        }
        ans -= (ll)(k - 1) * query(R[0]);
        cout << ans << '\n';
    }
    
    return 0;
}