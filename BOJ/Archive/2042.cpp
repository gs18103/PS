#include  <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

struct SEG {
    vector <ll> tree;
    int sz;
    bool base;

    SEG(int n, bool _base = true) : base(_base) {
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.resize(sz<<1);
    }
    void clear() { for(auto &i : tree) i = 0; }

    void update(int k, ll val) {
        int node = k + sz - base;
        tree[node] = val;
        while(node >>= 1) {
            tree[node] = tree[node<<1] + tree[node<<1|1];
        }
    }

    ll cal(int l, int r) {
        ll ret = 0;
        for(l += sz - base, r += sz - base; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) ret += tree[l++];
            if(~r & 1) ret += tree[r--];
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <ll> a(n+1);
    SEG ST(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ST.update(i, a[i]);
    }
    for(int i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1) ST.update(b, c);
        else cout << ST.cal(min(b, c), max(b, c)) << '\n';
    }
}