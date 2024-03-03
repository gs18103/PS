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
const int INF = 1 << 30;  
const ll LINF = 1LL << 60;  
  
struct node {  
    int l, r; pii val;  
    node(int l, int r, pii val) : l(l), r(r), val(val) {}  
};  
vector <node> tree;  
vector <pii> g[MAX];  
int root[MAX];  
int d[MAX];  
int s[MAX], v[MAX];
ll dp[MAX];  
  
ll f(pii l, ll x) {  
    return (ll)l.fi * x + dp[l.se];  
}  
  
void expand_tree(int s, int e, pii val, int cnd, int pnd) {  
    int m = (s + e) / 2;  
    tree[cnd].val = tree[pnd].val;  
    bool left = f(val, s) < f(tree[cnd].val, s);  
    bool mid = f(val, m) < f(tree[cnd].val, m);  
    if(mid) swap(tree[cnd].val, val);  
    if(e == s + 1) return;  
    if(mid == left) {  
        tree[cnd].l = tree[pnd].l;  
        tree[cnd].r = tree.size();  
        tree.eb(0, 0, make_pair(0, 0));  
        expand_tree(m, e, val, tree[cnd].r, tree[pnd].r);  
    }  
    else {  
        tree[cnd].r = tree[pnd].r;  
        tree[cnd].l = tree.size();  
        tree.eb(0, 0, make_pair(0, 0));  
        expand_tree(s, m, val, tree[cnd].l, tree[pnd].l);  
    }  
}  
  
ll cal(int node, int s, int e, ll x) {  
    int m = (s + e) / 2;  
    if(e == s + 1) return f(tree[node].val, x);  
    if(x < m) return min(f(tree[node].val, x), cal(tree[node].l, s, m, x));  
    else return min(f(tree[node].val, x), cal(tree[node].r, m, e, x));  
}  
  
void dfs(int x, int pa) {  
    dp[x] = cal(root[pa], 1, INF, v[x]) + (ll)s[x] + (ll)v[x] * d[x];  
    root[x] = tree.size();  
    tree.eb(0, 0, make_pair(0, 0));  
    expand_tree(1, INF, make_pair(-d[x], x), root[x], root[pa]);  
    for(auto i : g[x]) {  
        if(i.fi == pa) continue;  
        d[i.fi] = d[x] + i.se;  
        dfs(i.fi, x);  
    }  
}  
  
int main() {  
    ios::sync_with_stdio(false); cin.tie(0);  
    int n;  
    cin >> n;  
    for(int i = 1; i < n; i++) {  
        int u, v, w; cin >> u >> v >> w;  
        g[u].eb(v, w), g[v].eb(u, w);  
    }  
    for(int i = 2; i <= n; i++) {  
        cin >> s[i] >> v[i];  
    }  
    tree.eb(0, 0, make_pair(0, 0));  
    for(auto i : g[1]) {  
        d[i.fi] = i.se;  
        dfs(i.fi, 1);  
    }  
    for(int i = 2; i <= n; i++) {  
        cout << dp[i] << ' ';  
    }  
}  