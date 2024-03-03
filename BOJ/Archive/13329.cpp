#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

ll ccw(pll a, pll b, pll c) {
    return (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
}

struct Line {
    pll p1, p2;
    int idx;
    bool operator < (const Line T) const {
        if(ccw({0, 0}, p1, T.p1) > 0 && ccw({0, 0}, T.p1, p2) > 0) return ccw(p1, p2, T.p1) < 0;
        else if(ccw({0, 0}, p1, T.p2) > 0 && ccw({0, 0}, T.p2, p2) > 0) return ccw(p1, p2, T.p2) < 0;
        else return ccw(T.p1, T.p2, p1) > 0;
    }
};

Line line[MAX];
vector <int> g[MAX];
int in[MAX], L[MAX], R[MAX];

class SegmentTree {
    vector <bool> tree, lazy;
    int sz;
public:
    void Init(int n) {
        tree.resize(4*n+10);
        lazy.resize(4*n+10);
        sz = n;
    }
    void update_lazy(int node, int s, int e) {
        if(!lazy[node]) return;
        tree[node] = true;
        if(s != e) {
            lazy[node<<1] = lazy[node<<1|1] = true;
        }
        lazy[node] = false;
    }
    void update(int node, int s, int e, int l, int r) {
        update_lazy(node, s, e);
        if(s > r | e < l) return;
        if(s >= l && e <= r) {
            lazy[node] = true;
            update_lazy(node, s, e);
            return;
        }
        int m = (s + e) >> 1;
        update(node<<1, s, m, l, r);
        update(node<<1|1, m+1, e, l, r);
        tree[node] = tree[node<<1] && tree[node<<1|1];
    }
    void Update(int l, int r) {
        update(1, 1, sz, l, r);
    }
    
    bool cal(int node, int s, int e, int l, int r) {
        update_lazy(node, s, e);
        if(s > r || e < l) return true;
        if(s >= l && e <= r) return tree[node];
        int m = (s + e) >> 1;
        return cal(node<<1, s, m, l, r) && cal(node<<1|1, m+1, e, l, r);
    }
    bool Cal(int l, int r) {
        return cal(1, 1, sz, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector <pair <pll, int> > pt;
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        vector <pll> temp(k);
        for(int j = 0; j < k; j++) {
            cin >> temp[j].fi >> temp[j].se;
        }
        sort(all(temp), [](pll a, pll b) {
            return ccw({0, 0}, a, b) > 0;
        });
        pt.eb(temp[0], i);
        pt.eb(temp.back(), i);
        line[i].p1 = temp[0];
        line[i].p2 = temp.back();
        line[i].idx = i;
    }
    sort(all(pt), [](pair <pll, int> a, pair <pll, int> b) {
        return ccw({0, 0}, a.fi, b.fi) > 0;
    });
    set <Line> st;
    int cnt = 0;
    for(auto i : pt) {
        if(i.fi == line[i.se].p2) {
            auto it = st.find(line[i.se]);
            if(it != st.begin()) {
                g[prev(it)->idx].eb(it->idx);
                in[it->idx]++;
            }
            if(next(it) != st.end()) {
                g[it->idx].eb(next(it)->idx);
                in[next(it)->idx]++;
            }
            st.erase(it);
            R[i.se] = ++cnt;
        }
        else {
            st.em(line[i.se]);
            L[i.se] = ++cnt;
        }
    }
    
    queue <int> q;
    SegmentTree ST;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) q.em(i);
    }
    ST.Init(4*n);
    int ans = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(ST.Cal(2*L[x], 2*R[x])) ans++;
        ST.Update(2*L[x], 2*R[x]);
        for(auto i : g[x]) {
            in[i]--;
            if(in[i] == 0) q.em(i);
        }
    }
    cout << ans;
}
