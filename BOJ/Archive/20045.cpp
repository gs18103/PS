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

const int MAX = 303030;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

ll arr[MAX], sum[MAX];

class PersistentSegmentTree {
    struct Node {
        int l, r, val;
        Node(int l, int r, int val) : l(l), r(r), val(val) {}
    };
    vector <Node> tree;
    vector <int> root;
    int sz;
public:
    void Init(int n) {
        sz = n;
        root.eb(0);
        tree.eb(0, 0, 0);
    }
    void expand_tree(int s, int e, int k, int pnd, int cnd) {
        tree[cnd].val = tree[pnd].val + 1;
        if(s == e) return;
        int m = s + e >> 1;
        if(k <= m) {
            tree[cnd].r = tree[pnd].r;
            tree[cnd].l = tree.size();
            tree.eb(0, 0, 0);
            expand_tree(s, m, k, tree[pnd].l, tree[cnd].l);
        }
        else {
            tree[cnd].l = tree[pnd].l;
            tree[cnd].r = tree.size();
            tree.eb(0, 0, 0);
            expand_tree(m+1, e, k, tree[pnd].r, tree[cnd].r);
        }
    }

    void make_new(int k) {
        root.eb(tree.size());
        tree.eb(0, 0, 0);
        expand_tree(0, sz, k, root[root.size()-2], root.back());
    }

    int get_kth(int r, int k) {
        return cal(0, sz, root[r], k);
    }
    int cal(int s, int e, int cnd, int k) {
        if(s == e) return s;
        int cnt = tree[tree[cnd].l].val, m = s + e >> 1;
        if(cnt >= k) return cal(s, m, tree[cnd].l, k);
        else return cal(m+1, e, tree[cnd].r, k - cnt);
    }
};
vector <ll> num;
int cnt[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; ll k;
    cin >> n >> k;
    num.eb(0);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
        num.eb(sum[i]);
    }
    sort(all(num));
    PersistentSegmentTree PST;
    PST.Init(n);
    for(int i = 0; i <= n; i++) {
        PST.make_new(lower_bound(all(num), sum[i]) - num.begin());
    }
    priority_queue <pair <ll ,int> > pq;
    for(int i = 1; i <= n; i++) {
        pq.em(sum[i] - num[PST.get_kth(i, 1)], i);
        cnt[i] = 1;
    }
    vector <ll> ans;
    for(int i = 0; i < k; i++) {
        ll val = pq.top().fi, idx = pq.top().se;
        pq.pop();
        ans.eb(val);
        cnt[idx]++;
        if(cnt[idx] <= idx) pq.em(sum[idx] - num[PST.get_kth(idx, cnt[idx])], idx);
    }
    sort(all(ans));
    reverse(all(ans));
    for(auto i : ans) cout << i << ' ';
}