#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int INF = 1 << 30;
const ll LINF = 1LL << 62;
const int MAX = 101010;

int A[3*MAX], in[3*MAX], out[3*MAX], dep[3*MAX], p[3*MAX], cnt, n;
bool tree[12*MAX];
vector <int> g[3*MAX], color_group[3*MAX];

void dfs(int x, int pa) {
    in[x] = out[x] = ++cnt;
    dep[x] = dep[pa] + 1;
    p[x] = pa;
    for(auto i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
        out[x] = max(out[x], out[i]);
    }
}

void update(int node, int s, int e, int k) {
    if(s == e) {tree[node] = !tree[node]; return;}
    int m = (s + e) / 2;
    if(k <= m) update(node*2, s, m, k);
    else update(node*2+1, m+1, e, k);
    tree[node] = tree[node*2] || tree[node*2+1];
}

bool cal(int node, int s, int e, int l, int r) {
    if(s >= l && e <= r) return tree[node];
    if(s > r || e < l) return false;
    int m = (s + e) / 2;
    return cal(node*2, s, m, l, r) || cal(node*2+1, m+1, e, l, r);
}

bool range_tree[12*MAX];

void update_range(int node, int s, int e, int l, int r) {
    if(s >= l && e <= r) {range_tree[node] = true; return;}
    if(s > r || e < l) return;
    int m = (s + e) / 2;
    update_range(node*2, s, m, l, r);
    update_range(node*2+1, m+1, e, l, r);
    
}

bool cal_ans(int node, int s, int e, int k) {
    if(s == e) return range_tree[node];
    int m = (s + e) / 2;
    if(k <= m) return range_tree[node] || cal_ans(node*2, s, m, k);
    else return range_tree[node] || cal_ans(node*2+1, m+1, e, k);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        color_group[A[i]].eb(i);
    }
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    dfs(1, 0);

    for(int i = 1; i <= n; i++) {
        sort(all(color_group[i]), [](int a, int b) {
            return dep[a] > dep[b];
        });
        for(auto j : color_group[i]) {
            if(cal(1, 1, n, in[j], out[j])) {
                update_range(1, 1, n, 1, in[j]);
                update_range(1, 1, n, out[j]+1, n);
                
                for(auto k : g[j]) {
                    if(k == p[j]) continue;
                    if(cal(1, 1, n, in[k], out[k])) {
                        update_range(1, 1, n, in[j], in[k]-1);
                        update_range(1, 1, n, out[k]+1, out[j]);
                    }
                }
            }
            update(1, 1, n, in[j]);
        }
        for(auto j : color_group[i]) {
            if(cal(1, 1, n, 1, in[j]-1) || cal(1, 1, n, out[j]+1, n)) {
                update_range(1, 1, n, in[j], out[j]);
            }
        }
        for(auto j : color_group[i]) {
            update(1, 1, n, in[j]);
        }
    }

    ll ans = 0, sqans = 0, anscnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!cal_ans(1, 1, n, in[i])) {
            ans += i;
            sqans += (ll)i * i;
            anscnt++;
        }
    }
    cout << anscnt << endl << ans << endl << sqans << endl;
}