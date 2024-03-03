#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

struct Pt {
    int x, y, g;
};

struct SEG {
    vector <int> tree, lazy;
    int sz;
    void Init(int n) {
        sz = n;
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

    void update(int node, int s, int e, int l, int r, int val) {
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
    void update(int l, int r, int val) {
        update(1, 1, sz, l, r, val);
    }

    int cal() {
        update_lazy(1, 1, sz);
        return tree[1];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector <Pt> p(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> p[i].g >> x >> y;
        p[i].x = x + y;
        p[i].y = y - x;
    }

    sort(all(p), [](Pt a, Pt b) {
        return a.y < b.y;
    });

    int idx = 0, ans = 0;
    SEG ST;
    ST.Init(2'000'000);
    for(int i = 0; i < n; i++) {
        ST.update(p[i].x, p[i].x + 2 * k, p[i].g);
        while(idx < i && p[idx].y + 2 * k < p[i].y) {
            ST.update(p[idx].x, p[idx].x + 2 * k, -p[idx].g);
            idx++;
        }
        ans = max(ans, ST.cal());
    }
    cout << ans;
}