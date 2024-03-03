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

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

vector < pair <int, ll> > g[MAX];

ll dpr[MAX], ans, dppm[MAX], dppr[MAX], val[MAX];
pll dpm1[MAX], dpm2[MAX], dpm3[MAX];

void dfs1(int x, int pa) {
    pll rm1 = {0, 0}, rm2 = {0, 0};
    for(auto i : g[x]) {
        int y = i.fi;
        ll w = i.se;
        if(y == pa) continue;
        val[y] = w;
        dfs1(y, x);
        dpr[x] = max(dpr[x], dpr[y]);
        if(dpm1[y].fi + w > dpm3[x].fi) {
            dpm3[x].fi = dpm1[y].fi + w;
            dpm3[x].se = y;
            if(dpm3[x] > dpm2[x]) swap(dpm2[x], dpm3[x]);
            if(dpm2[x] > dpm1[x]) swap(dpm1[x], dpm2[x]);
        }
    }
    dpr[x] = max(dpr[x], dpm1[x].fi + dpm2[x].fi);
}

void dfs2(int x, int pa) {
    pll rm1 = {0, 0}, rm2 = {0, 0};
    for(auto i : g[x]) {
        int y = i.fi;
        ll w = i.se;
        if(y == pa) continue;
        if(dpr[y] > rm2.fi) {
            rm2.fi = dpr[y];
            rm2.se = y;
            if(rm2 > rm1) swap(rm1, rm2);
        }
    }
    for(auto i : g[x]) {
        int y = i.fi;
        ll w = i.se;
        if(y == pa) continue;   
        if(y == rm1.se) {
            dppr[y] = max(rm2.fi, dppr[x]);
        }
        else {
            dppr[y] = max(rm1.fi, dppr[x]);
        }
        if(y == dpm1[x].se) {
            dppm[y] = max(dpm2[x].fi, dppm[x]) + w;
            dppr[y] = max(dppr[y], dpm2[x].fi + max(dpm3[x].fi, dppm[x]));
        }
        else if(y == dpm2[x].se) {
            dppm[y] = max(dpm1[x].fi, dppm[x]) + w;
            dppr[y] = max(dppr[y], dpm1[x].fi + max(dpm3[x].fi, dppm[x]));
        }
        else {
            dppm[y] = max(dpm1[x].fi, dppm[x]) + w;
            dppr[y] = max(dppr[y], dpm1[x].fi + max(dpm2[x].fi, dppm[x]));
        }
        dfs2(y, x);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    dfs1(1, 0);
    dfs2(1, 0);
    for(int i = 2; i <= n; i++) {
        ans = max(ans, dppr[i] + val[i] + dpr[i]);
    }
    cout << ans << endl;
}