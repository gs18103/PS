#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 505050;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

class SegmentTree {
    vector <int> tree;
    int sz;
public:
    void Init(int n, int x) {
        sz = n;
        tree.resize(4*n+10);
        for(int i = 0; i < tree.size(); i++) tree[i] = x;
    }

    void update(int node, int s, int e, int k, int val) {
        if(s == e) {
            tree[node] = max(tree[node], val);
            return;
        }
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, val);
        else update(node<<1|1, m+1, e, k, val);
        tree[node] = max(tree[node<<1], tree[node<<1|1]);
    }
    void Update(int k, int val) {
        update(1, 1, sz, k, val);
    }

    int cal(int node, int s, int e, int l, int r) {{
        if(s > r || e < l) return 0;
        if(s >= l && e <= r) return tree[node];
        int m = s + e >> 1;
        return max(cal(node<<1, s, m, l, r), cal(node<<1|1, m+1, e, l, r));
    }}
    int get_max(int l, int r) {
        return cal(1, 1, sz, l, r);
    }
};

int arr[MAX], dpd[3][MAX], dpu[3][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> num;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        num.eb(arr[i]);
    }
    sort(all(num));
    for(int i = 1; i <= n; i++) {
        arr[i] = lower_bound(all(num), arr[i]) - num.begin() + 1;
    }
    SegmentTree STU1, STU2, STD1, STD2;
    STU1.Init(n, 0);
    STU2.Init(n, 0);
    STD1.Init(n, 0);
    STD2.Init(n, 0);

    for(int i = 1; i <= n; i++) {
        dpd[1][i] = STU2.get_max(1, arr[i]) + 1;
        dpd[2][i] = max(STD2.get_max(arr[i], n), STD1.get_max(arr[i], n)) + 1;
        dpu[1][i] = STD2.get_max(arr[i], n) + 1;
        dpu[2][i] = max(STU2.get_max(1, arr[i]), STU1.get_max(1, arr[i])) + 1;
        STD1.Update(arr[i], dpd[1][i]);
        if(dpd[2][i] > 1) STD2.Update(arr[i], dpd[2][i]);
        STU1.Update(arr[i], dpu[1][i]);
        if(dpu[2][i] > 1) STU2.Update(arr[i], dpu[2][i]);
    }
    int ans = max(STD1.get_max(1, n), STU1.get_max(1, n));
    if(ans >= 3) cout << ans;
    else cout << 0;
}