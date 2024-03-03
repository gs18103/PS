#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const ll LINF = 1e13;

struct SEG {
    vector <ll> tree, lazy;
    int sz;
    SEG(int n) : sz(n) {
        tree.resize(4*n+10);
        lazy.resize(4*n+10);
    }

    void update_lazy(int node, int s, int e) {
        tree[node] += lazy[node];
        if(s != e) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(int l, int r, ll val) {
        update(1, 1, sz, l, r, val);
    }
    void update(int node, int s, int e, int l, int r, ll val) {
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            lazy[node] += val;
            update_lazy(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update(node<<1, s, m, l, r, val);
        update(node<<1|1, m+1, e, l, r, val);
        tree[node] = max(tree[node<<1], tree[node<<1|1]);
    }

    vector <int> largest(vector <int> &rvs) {
        update_lazy(1, 1, sz);
        ll val = tree[1];
        vector <int> ret;
        get(1, 1, sz, val, ret, rvs);
        sort(all(ret));
        return ret;
    }
    void get(int node, int s, int e, ll val, vector <int> &ret, vector <int> &rvs) {
        if(s == e) {
            if(tree[node] == val) ret.eb(rvs[s]);
            return;
        }
        int m = s + e >> 1;
        update_lazy(node<<1, s, m);
        update_lazy(node<<1|1, m+1, e);
        if(tree[node<<1] == val) get(node<<1, s, m, val, ret, rvs);
        if(tree[node<<1|1] == val) get(node<<1|1, m+1, e, val, ret, rvs);
    }
};

void dfs(int x, int pa, int &num, vector <int> &in, vector <int> &out, vector <vector <pll>> &g, SEG &ST) {
    in[x] = ++num;
    for(auto i : g[x]) {
        if(i.fi == pa) continue;
        dfs(i.fi, x, num, in, out, g, ST);
        ST.update(in[i.fi], out[i.fi], i.se);
    }
    out[x] = num;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector <vector <pll>> g(n+1);
    vector <pii> E(n+1);
    vector <int> in(n+1), out(n+1), rvs(n+1);
    for(int i = 1; i < n; i++) {
        int u, v; ll d;
        cin >> u >> v >> d;
        g[u].eb(v, d), g[v].eb(u, d);
        E[i] = pii(u, v);
    }
    for(int i = 1; i <= n; i++) {
        sort(all(g[i]));
    }
    SEG ST(n);
    int num = 0;
    dfs(1, 0, num, in, out, g, ST);
    for(int i = 1; i <= n; i++) {
        rvs[in[i]] = i;
    }

    int q;
    int cur = 1;
    cin >> q;
    while(q--) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            ll val = lower_bound(all(g[cur]), pll(x, 0))->se;
            if(in[x] < in[cur]) {
                ST.update(in[cur], out[cur], val);
                ST.update(1, in[cur]-1, -val);
                ST.update(out[cur]+1, n, -val);
            }
            else {
                ST.update(in[x], out[x], -val);
                ST.update(1, in[x]-1, val);
                ST.update(out[x]+1, n, val);
            }
            cur = x;
        }
        if(t == 2) {
            int u = E[x].fi, v = E[x].se;
            if(in[u] > in[v]) swap(u, v); // now p[v] = u
            if(in[v] <= in[cur] && out[cur] <= out[v]) {
                ST.update(1, in[v]-1, -LINF);
                ST.update(out[v]+1, n, -LINF);
            }
            else ST.update(in[v], out[v], -LINF);
        }
        if(t == 3) {
            int u = E[x].fi, v = E[x].se;
            if(in[u] > in[v]) swap(u, v); // now p[v] = u
            if(in[v] <= in[cur] && out[cur] <= out[v]) {
                ST.update(1, in[v]-1, LINF);
                ST.update(out[v]+1, n, LINF);
            }
            else ST.update(in[v], out[v], LINF);
        }
        vector <int> ans = ST.largest(rvs);
        cout << ans.size() << ' ';
        for(int i : ans) cout << i << ' ';
        cout << '\n';
    }
}