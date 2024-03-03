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

vector <int> g[MAX];
int in[MAX], out[MAX];
int num;

struct SEG {
    vector <int> tree;
    int sz;
    SEG(int n) : sz(n) {
        tree.resize(4*n+10);
    }
    
    void update(int k, int val) {
        update(1, 1, sz, k, val);
    }
    void update(int node, int s, int e, int k, int val) {
        if(s == e) {
            tree[node] += val;
            return;
        }
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, val);
        else update(node<<1|1, m+1, e, k, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
    
    int cal(int l, int r) {
        return cal(1, 1, sz, l, r);
    }
    int cal(int node, int s, int e, int l, int r) {
        if(s > r || e < l) return 0;
        if(s >= l && e <= r) return tree[node];
        int m = s + e >> 1;
        return cal(node<<1, s, m, l, r) + cal(node<<1|1, m+1, e, l, r);
    }
};

void dfs(int x) {
    in[x] = out[x] = ++num;
    for(int i : g[x]) {
        dfs(i);
        out[x] = max(out[x], out[i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int p; cin >> p;
        if(p < 0) continue;
        g[p].eb(i);
    }
    
    dfs(1);
    SEG ST(n);
    
    while(m--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, val;
            cin >> x >> val;
            ST.update(in[x], val);
        }
        if(t == 2) {
            int x;
            cin >> x;
            cout << ST.cal(in[x], out[x]) << '\n';
        }
    }
}
