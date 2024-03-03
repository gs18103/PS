#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 505050;
const int INF = 1e9;
const ll LINF = 1e18;

int in[MAX], out[MAX], top[MAX], c[MAX], dep[MAX], p[MAX], cnt, n, q;
vector <int> g[MAX];

void dfs_sz(int x, int pa) {
    c[x] = 1; dep[x] = dep[pa] + 1; p[x] = pa;
    for(auto &i : g[x]) {
        if(i == pa) {
            if(i == g[x][0] && g[x].size() >= 2) {
                dfs_sz(g[x][1], x); c[x] += c[g[x][1]];
                swap(g[x][0], g[x][1]);
            }
            continue;
        }
        dfs_sz(i, x); c[x] += c[i];
        if(c[i] > c[g[x][0]]) swap(i, g[x][0]);
    }
}

void dfs_hld(int x, int pa) {
    in[x] = ++cnt;
    for(auto i : g[x]) {
        if(i == pa) continue;
        top[i] = (i == g[x][0] ? top[x] : i);
        dfs_hld(i, x);
    }
    out[x] = cnt;
}

struct SEG {
    uint tree[4*MAX];
    pair <uint, uint> lazy[4*MAX];

    void update_lazy(int node, int s, int e) {
        tree[node] = tree[node] * lazy[node].fi + lazy[node].se * (e - s + 1);
        if(s != e) {
            for(int i = node*2; i <= node*2+1; i++) {
                lazy[i].se = lazy[i].se * lazy[node].fi + lazy[node].se;
                lazy[i].fi = lazy[i].fi * lazy[node].fi;
            }
        }
        lazy[node] = make_pair((uint)1, 0);
    }

    void update(int node, int s, int e, int l, int r, pair <uint, uint> val) {
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            lazy[node].se = lazy[node].se * val.fi + val.se;
            lazy[node].fi = lazy[node].fi * val.fi;
            update_lazy(node, s, e);
            return;
        }
        int m = (s + e) / 2;
        update(node*2, s, m, l, r, val), update(node*2+1, m+1, e, l, r, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    uint cal(int node, int s, int e, int l, int r) {
        update_lazy(node, s, e);
        if(s > r || e < l) return (uint)0;
        if(s >= l && e <= r) return tree[node];
        int m = (s + e) / 2;
        return cal(node*2, s, m, l, r) + cal(node*2+1, m+1, e, l, r);
    }
} st;

void query13(int x, pair <uint, uint> v) {
    st.update(1, 1, n, in[x], out[x], v);
}

void query24(int x, int y, pair <uint, uint> v) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        st.update(1, 1, n, in[top[x]], in[x], v);
        x = p[top[x]];
    }
    if(dep[x] < dep[y]) swap(x, y);
    st.update(1, 1, n, in[y], in[x], v);
}

uint query5(int x) {
    return st.cal(1, 1, n, in[x], out[x]);
}

uint query6(int x, int y) {
    uint ret = 0;
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        ret += st.cal(1, 1, n, in[top[x]], in[x]);
        x = p[top[x]];
    }
    if(dep[x] < dep[y]) swap(x, y);
    ret += st.cal(1, 1, n, in[y], in[x]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i = 0; i < 4*MAX; i++) st.lazy[i] = make_pair((uint)1, 0);

    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    dfs_sz(1, 0);
    top[1] = 1;
    dfs_hld(1, 0);

    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x; uint v; cin >> x >> v;
            query13(x, make_pair(1, v));
        }
        if(t == 2) {
            int x, y; uint v; cin >> x >> y >> v;
            query24(x, y, make_pair(1, v));
        }
        if(t == 3) {
            int x; uint v; cin >> x >> v;
            query13(x, make_pair(v, 0));
        }
        if(t == 4) {
            int x, y; uint v; cin >> x >> y >> v;
            query24(x, y, make_pair(v, 0));
        }
        if(t == 5) {
            int x; cin >> x;
            cout << query5(x) << '\n';
        }
        if(t == 6) {
            int x, y; cin >> x >> y;
            cout << query6(x, y) << '\n';
        }
    }
}