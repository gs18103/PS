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

const int MAX = 303030;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

class SegmentTree {
    vector <pll> tree;
    int sz;

    void init(int node, int s, int e, vector <pll> &A) {
        if(s == e) {
            tree[node].fi = A[s].fi;
            tree[node].se = s;
            return;
        }
        int m = s + e >> 1;
        init(node<<1, s, m, A);
        init(node<<1|1, m+1, e, A);
        tree[node] = min(tree[node<<1], tree[node<<1|1]);
    }

    pll cal(int node, int s, int e, int l, int r) {
        if(s > r || e < l) return {LINF, -1};
        if(s >= l && e <= r) return tree[node];
        int m = s + e >> 1;
        return min(cal(node<<1, s, m, l, r), cal(node<<1|1, m+1, e, l, r));
    }

public:

    void Init(vector <pll> &A) {
        sz = A.size();
        tree.resize(4*sz+10);
        init(1, 0, sz-1, A);
    }

    int mnidx(int l, int r) {
        return cal(1, 0, sz-1, l, r).se;
    }
} ST;

vector <pll> h;
vector <ll> sum, w, g[MAX];

int dnc(int s, int e, int bh) {
    if(s == e) {
        w[s] = (h[s].fi - bh) * h[s].se;
        return s;
    }
    int idx = ST.mnidx(s, e);
    if(s) w[idx] = (h[idx].fi - bh) * (sum[e] - sum[s-1]);
    else w[idx] = (h[idx].fi - bh) * sum[e];

    if(idx > s) {
        int u = dnc(s, idx - 1, h[idx].fi);
        g[idx].eb(u);
    }
    if(idx < e) {
        int u = dnc(idx + 1, e, h[idx].fi);
        g[idx].eb(u);
    }
    return idx;
}

multiset <ll, greater <ll> > st;

ll dfs(int x) {
    if(g[x].empty()) return w[x];
    ll mx = 0;
    for(auto i : g[x]) {
        ll temp = dfs(i);
        mx = max(mx, temp);
        st.em(temp);
    }
    st.erase(st.find(mx));
    return mx + w[x];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, x, y, k;
    cin >> n;
    cin >> x >> y;
    for(int i = 2; i <= n; i++) {
        int nx, ny;
        cin >> nx >> ny;
        if(y == ny) {
            h.eb(y, nx - x);
        }
        x = nx, y = ny;
    }
    cin >> k;

    ST.Init(h);
    sum.resize(h.size());
    w.resize(h.size());
    sum[0] = h[0].se;
    for(int i = 1; i < h.size(); i++) {
        sum[i] = sum[i-1] + h[i].se;
    }

    int root = dnc(0, h.size() - 1, 0);
    st.em(dfs(root));

    auto it = st.begin();
    ll ans = 0;
    for(int i = 0; i < k && it != st.end(); i++, it = next(it)) {
        ans += *it;
    }
    cout << ans << endl;;
}