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

const int INF = 1e9;
const ll LINF = 1e18;

struct SEG {
    vector <vector <pii>> tree;
    int sz;
    SEG(int n) {
        for(sz = 1; sz < n; sz <<= 1) ;
        tree.resize(sz<<1);
    }

    void update(int x, pii val) {
        int node = x + sz;
        tree[node].eb(val);
        while(node >>= 1) tree[node].eb(val);
    }

    vector <int> get(int x, int y) {
        vector <int> ret;
        for(int l = sz, r = x + sz; l <= r; l >>= 1, r >>= 1) {
            if(~r & 1) {
                while(!tree[r].empty() && tree[r].back().fi <= y) {
                    ret.eb(tree[r].back().se);
                    tree[r].pop_back();
                }
                r--;
            }
        }
        return ret;
    }
};

struct Line {
    int x, y, nx, ny, c;
    ll ans = LINF;
    bool st = false, ed = false;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector <Line> v(m);
    vector <int> X;
    for(int i = 0; i < m; i++) {
        int t, l, r;
        cin >> t >> l >> r >> v[i].c;
        v[i].x = l - t, v[i].y = l + t, v[i].nx = r + 1 - t, v[i].ny = r + 1 + t;
        if(l == 1) v[i].st = true, v[i].ans = v[i].c;
        if(r == n) v[i].ed = true;
        X.eb(v[i].x), X.eb(v[i].nx);
    }
    
    sort(all(X));
    X.erase(unique(all(X)), X.end());
    sort(all(v), [](Line a, Line b) {
        return a.y > b.y;
    });

    SEG ST(X.size());
    priority_queue <pll, vector <pll>, greater <pll>> pq;
    for(int i = 0; i < m; i++) {
        v[i].x = lower_bound(all(X), v[i].x) - X.begin();
        v[i].nx = lower_bound(all(X), v[i].nx) - X.begin();
        if(v[i].st) pq.em(v[i].ans, i);
        else ST.update(v[i].x, pii(v[i].y, i));
    }

    while(!pq.empty()) {
        int cur = pq.top().se;
        pq.pop();
        vector <int> next = ST.get(v[cur].nx, v[cur].ny);
        for(int i : next) {
            if(v[i].ans < LINF) continue;
            v[i].ans = v[cur].ans + v[i].c;
            pq.em(v[i].ans, i);
        }
    }

    ll ans = LINF;
    for(int i = 0; i < m; i++) {
        if(v[i].ed) ans = min(ans, v[i].ans);
    }
    if(ans == LINF) cout << "-1\n";
    else cout << ans << '\n';
}