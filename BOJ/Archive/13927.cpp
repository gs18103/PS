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
const ll LINF = 1e18;

int n;

class PersistentSegmentTree {
    struct Node {
        int l = 0, r = 0, val = 0;
        Node(int l, int r, int val) : l(l), r(r), val(val) {}
    };
    vector <Node> tree;
public:
    vector <int> root;

    PersistentSegmentTree() {
        tree.eb(0, 0, 0);
        root.eb(0);
    }

    void add(int k, int val) {
        root.eb(tree.size());
        tree.eb(0, 0, 0);
        update(root[root.size()-1], root[root.size()-2], k, val, 1, n);
    }

    void update(int cnd, int pnd, int k, int val, int s, int e) {
        tree[cnd].val = tree[pnd].val + val;
        if(s == e) return;
        int m = s + e >> 1;
        if(k <= m) {
            tree[cnd].r = tree[pnd].r;
            tree[cnd].l = tree.size();
            tree.eb(0, 0, 0);
            update(tree[cnd].l, tree[pnd].l, k, val, s, m);
        }
        else {
            tree[cnd].l = tree[pnd].l;
            tree[cnd].r = tree.size();
            tree.eb(0, 0, 0);
            update(tree[cnd].r, tree[pnd].r, k, val, m + 1, e);
        }
    }

    int cal(int l, int r) {
        return cal(root[r], l, n, 1, n);
    }

    int cal(int cnd, int l, int r, int s, int e) {
        if(s > r || e < l) return 0;
        if(s >= l && e <= r) return tree[cnd].val;
        int m = s + e >> 1;
        return cal(tree[cnd].l, l, r, s, m) + cal(tree[cnd].r, l, r, m+1, e);
    }
};

vector <PersistentSegmentTree> tree;
vector <vector <pii> > val;
vector <vector <int> > rtnum;

void ins(int node, int s, int e, pii v) {
    val[node].eb(v);
    if(s == e) return;
    int m = s + e >> 1;
    if(v.se <= m) ins(node*2, s, m, v);
    else ins(node*2+1, m+1, e, v);
}

void init(int node, int s, int e) {
    map <int, int> mp;
    for(int i = 0; i < val[node].size(); i++) {
        int idx = val[node][i].fi;
        int num = val[node][i].se;
        if(mp[num] > 0) tree[node].add(mp[num], -1);
        mp[num] = idx;
        rtnum[node].eb(tree[node].root.size());
        tree[node].add(idx, 1);
    }
    if(s == e) return;
    int m = s + e >> 1;
    init(node*2, s, m);
    init(node*2+1, m+1, e);
}

int get_kth(int node, int s, int e, int l, int r, int k) {
    if(s == e) {
        int idx = upper_bound(all(val[node]), make_pair(r, INF)) - val[node].begin() - 1;
        int c;
        if(idx >= 0) c = tree[node].cal(l, rtnum[node][idx]);
        else c = 0;
        if(k == 1 && c == 1) return s;
        else return 0;
    }
    int m = s + e >> 1;
    int idx = upper_bound(all(val[2*node]), make_pair(r, INF)) - val[2*node].begin() - 1;
    int c;
    if(idx >= 0) c = tree[2*node].cal(l, rtnum[2*node][idx]);
    else c = 0;
    if(c >= k) return get_kth(node*2, s, m, l, r, k);
    else return get_kth(node*2+1, m+1, e, l, r, k - c);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    tree.resize(4*n+20);
    val.resize(4*n+20);
    rtnum.resize(4*n+20);
    vector <int> num(n), A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        num[i] = A[i];
    }
    num.eb(-1);
    sort(all(num));
    for(int i = 0; i < n; i++) {
        A[i] = lower_bound(all(num), A[i]) - num.begin();
        ins(1, 1, n, {i + 1, A[i]});
    }

    init(1, 0, n);

    int q, ans = 0;
    cin >> q;
    while(q--) {
        ll a, b, c, d;
        int k;
        cin >> a >> b >> c >> d >> k;
        int l = ((ll)a * max(ans, 0) + b) % n + 1;
        int r = ((ll)c * max(ans, 0) + d) % n + 1;
        //cin >> l >> r >> k;
        if(l > r) swap(l, r);
        ans = num[get_kth(1, 1, n, l, r, k)];
        cout << ans << '\n';
    }
}