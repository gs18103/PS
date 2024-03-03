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
const int INF = (int)1e9;
const ll LINF = (ll)1e63;

struct Query {
    int t, a, b;
};

Query q[MAX];
int p[MAX], rnk[MAX];
vector <pii> E[4*MAX];
vector <int> bp[4*MAX], br[4*MAX], ans;

void update(int node, int s, int e, int l, int r, pii k) {
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        E[node].eb(k);
        return;
    }
    int m = (s + e) / 2;
    update(node*2, s, m, l, r, k);
    update(node*2+1, m+1, e, l, r, k);
}

int find(int x) {
    if(x == p[x]) return x;
    return find(p[x]);
}   

void uni(int x, int y, int node) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(rnk[x] < rnk[y]) swap(x, y);
    p[y] = x;
    bp[node].eb(y);
    if(rnk[x] == rnk[y]) {
        rnk[x]++;
        br[node].eb(x);
    }
}

void dnc(int node, int s, int e) {
    for(auto i : E[node]) {
        uni(i.fi, i.se, node);
    }
    if(s == e) {
        if(q[s].t == 3) {
            if(find(q[s].a) == find(q[s].b)) ans.eb(1);
            else ans.eb(0);
        }
    }
    else {
        int m = (s + e) / 2;
        dnc(node*2, s, m);
        dnc(node*2+1, m+1, e);
    }
    for(auto i : br[node]) rnk[i]--;
    for(auto i : bp[node]) p[i] = i;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
    }
    map <pii, int> mp;
    for(int i = 1; i <= m; i++) {
        cin >> q[i].t >> q[i].a >> q[i].b;
        if(q[i].a > q[i].b) swap(q[i].a, q[i].b);
        if(q[i].t == 1) mp[{q[i].a, q[i].b}] = i;
        if(q[i].t == 2) {
            update(1, 1, m, mp[{q[i].a, q[i].b}], i, {q[i].a, q[i].b});
            mp.erase({q[i].a, q[i].b});
        }
    }
    for(auto i : mp) {
        update(1, 1, m, i.se, m, i.fi);
    }
    
    dnc(1, 1, m);

    for(int i : ans) {
        cout << i << '\n';
    }
}