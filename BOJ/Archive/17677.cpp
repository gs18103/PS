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

struct Node {
    int l, r, c; ll val;
    Node(int l, int r, int c, ll val) : l(l), r(r), c(c), val(val) {}
};

pll arr[2*MAX];
int root[2*MAX], n, x;
vector <Node> tree;
vector <ll> num;
ll ans = -LINF;

void expand_tree(int s, int e, int k, int pnd, int cnd) {
    tree[cnd].c = tree[pnd].c + 1;
    tree[cnd].val = tree[pnd].val + num[k];
    if(s == e) return;
    int m = s + e >> 1;
    if(k <= m) {
        tree[cnd].r = tree[pnd].r;
        tree[cnd].l = tree.size();
        tree.eb(0, 0, 0, 0LL);
        expand_tree(s, m, k, tree[pnd].l, tree[cnd].l);
    }
    else {
        tree[cnd].l = tree[pnd].l;
        tree[cnd].r = tree.size();
        tree.eb(0, 0, 0, 0LL);
        expand_tree(m+1, e, k, tree[pnd].r, tree[cnd].r);
    }
}

ll cal(int s, int e, int cnt, int pnd, int cnd) {
    if(s == e) return cnt * num[s];
    int m = s + e >> 1, rcnt = tree[tree[cnd].r].c - tree[tree[pnd].r].c;
    if(rcnt >= cnt) return cal(m+1, e, cnt, tree[pnd].r, tree[cnd].r);
    else {
        ll rval = tree[tree[cnd].r].val - tree[tree[pnd].r].val;
        return cal(s, m, cnt-rcnt, tree[pnd].l, tree[cnd].l) + rval;
    }
}

void dnc(int s, int e, int l, int r) {
    if(s > e) return;
    int idx = l, m = s + e >> 1;
    ll tans = -LINF;
    for(int i = l; i <= min(r, m - x + 1); i++) {
        ll temp = cal(1, n, x, root[i-1], root[m]);
        temp -= 2 * (arr[m].se - arr[i].se);
        if(temp > tans) {
            tans = temp;
            idx = i;
        }
    }
    ans = max(ans, tans);
    dnc(s, m-1, l, idx);
    dnc(m+1, e, idx, r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> x;
    num.eb(0);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].fi >> arr[i].se;
        num.eb(arr[i].fi);
    }
    sort(arr+1, arr+n+1, [](pll a, pll b) {
        if(a.se == b.se) return a.fi < b.fi;
        return a.se < b.se;
    });
    sort(all(num));
    
    tree.eb(0, 0, 0, 0);
    for(int i = 1; i <= n; i++) {
        int k = lower_bound(all(num), arr[i].fi) - num.begin();
        root[i] = tree.size();
        tree.eb(0, 0, 0, 0LL);
        expand_tree(1, n, k, root[i-1], root[i]);
    }

    dnc(1, n, 1, n);
    cout << ans;
}