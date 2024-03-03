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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

class SegmentTree {
    vector <map <int, int> > tree;
    int sz;
public:
    void Init(int n) {
        tree.resize(4*n+10);
        sz = n;
    }

    void update(int node, int s, int e, int k, int x, int val) {
        tree[node][x] += val;
        if(s == e) return;
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, x, val);
        else update(node<<1|1, m+1, e, k, x, val);
    }
    void update(int k, int x, int val) {
        update(1, 1, sz, k, x, val);
    }
    
    int cal(int node, int s, int e, int l, int r, int val) {
        if(s > r || e < l) return 0;
        if(s >= l && e <= r) return tree[node][val];
        int m = s + e >> 1;
        return cal(node<<1, s, m, l, r, val) + cal(node<<1|1, m+1, e, l, r, val);
    }
    int cal(int l, int r, int val) {
        return cal(1, 1, sz, l, r, val);
    }
};

int a[MAX], t[MAX], x[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> T;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> t[i] >> x[i];
        T.eb(t[i]);
    }
    sort(all(T));
    SegmentTree ST;
    ST.Init(n);
    for(int i = 1; i <= n; i++) {
        t[i] = lower_bound(all(T), t[i]) - T.begin() + 1;
        if(a[i] == 1) ST.update(t[i], x[i], 1);
        if(a[i] == 2) ST.update(t[i], x[i], -1);
        if(a[i] == 3) cout << ST.cal(1, t[i], x[i]) << '\n';
    }
}