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
const int INF = 1e9;
const ll LINF = 9e18;

pair <pii, ll> Edge[MAX];
vector <pair <int, ll> > g[MAX];

class SegmentTree {
    struct Node {
        ll lmx = -LINF, rmn = -LINF, lc = -LINF, rc = -LINF, c = -LINF, s = 0, mx = -LINF;
        Node operator + (Node b) {
            Node ret;
            ret.lmx = max(lmx, s + b.lmx);
            ret.rmn = max(b.rmn, rmn - b.s);
            ret.lc = max({lc, b.lc - s, b.lmx + c});
            ret.rc = max({b.rc, rc + b.s, rmn + b.c});
            ret.c = max(c + b.s, b.c - s);
            ret.s = s + b.s;
            ret.mx = max({mx, b.mx, rmn + b.lc, rc + b.lmx});
            return ret;
        }
    };
    vector <Node> tree;
    int sz;
public: 
    SegmentTree() {}
    void Init(int n) {
        sz = n;
        tree.resize(4*n+10);
    }

    void update(int node, int s, int e, int k, ll val) {
        if(s == e) {
            tree[node].lmx = tree[node].s = val;
            tree[node].rmn = -val;
            tree[node].mx = tree[node].lc = tree[node].rc = tree[node].c = abs(val);
            return;
        }
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, val);
        else update(node<<1|1, m+1, e, k, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    void Update(int k, ll val) {
        update(1, 1, sz, k, val);
    }

    ll get() {
        return tree[1].mx;
    }
} ST;

int in[MAX], out[MAX], cnt;

void dfs(int x, int pa) {
    in[x] = out[x] = cnt++;
    for(auto i : g[x]) {
        if(i.fi == pa) continue;
        ST.Update(cnt, i.se);
        dfs(i.fi, x);
        out[x] = cnt++;
        ST.Update(out[x], -i.se);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; ll W;
    cin >> n >> q >> W;
    ST.Init(2*n-2);
    for(int i = 0; i < n - 1; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        g[u].eb(v, w);
        g[v].eb(u, w);
        Edge[i] = {{u, v}, w};
    }

    dfs(1, 0);
    ll ans = 0;
    while(q--) {
        ll d, e;
        cin >> d >> e;
        d = (d + ans) % (n - 1);
        e = (e + ans) % W;
        int u = Edge[d].fi.fi, v = Edge[d].fi.se;
        if(in[u] < in[v]) swap(u, v);
        ST.Update(in[u], e);
        ST.Update(out[u]+1, -e);
        ans = ST.get();
        cout << ans << '\n';
    }
}