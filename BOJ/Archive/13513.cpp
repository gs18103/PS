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
const ll LINF = (ll)1e18;

struct iheap {
    priority_queue<int> a, b;
    int size() { return a.size() - b.size(); }
    void push(int x) { a.push(x); }
    void pop(int x) { b.push(x); }
    int top() {
        while (!a.empty() && !b.empty() && a.top() == b.top()) a.pop(), b.pop();
        return a.empty() ? -1 : a.top();
    }
    int second() {
        int x = top(); pop(x);
        int r = top(); push(x);
        return r;
    }
    int toptwo() {
        if (size() < 2) return -1;
        return top() + second();
    }
};

vector <pii> g[MAX];
vector <iheap> sub[MAX];
iheap submx[MAX], st;

int sz[MAX], crt, ctp[MAX], p[20][MAX], d[20][MAX], dep[MAX], n, c[MAX], ci[MAX];
bool chk[MAX];

void dfs(int x, int pa) {
    sz[x] = 1;
    p[0][x] = pa;
    dep[x] = dep[pa] + 1;
    for(int i = 1; i <= 17; i++) {
        p[i][x] = p[i-1][p[i-1][x]];
        d[i][x] = d[i-1][x] + d[i-1][p[i-1][x]];
    }
    for(auto i : g[x]) {
        if(i.fi == pa) continue;
        d[0][i.fi] = i.se;
        dfs(i.fi, x);
        sz[x] += sz[i.fi];
    }
}

int dist(int u, int v) {
    int ret = 0;
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 17; i >= 0; i--) {
        if(dep[v] - dep[u] >= (1 << i)) {
            ret += d[i][v];
            v = p[i][v];
        }
    }
    if(u == v) return ret;
    for(int i = 17; i >= 0; i--) {
        if(p[i][u] != p[i][v]) {
            ret += d[i][u] + d[i][v];
            u = p[i][u];
            v = p[i][v];
        }
    }
    return ret + d[0][u] + d[0][v];
}

int find_cen(int x) {
    int csz = 1, mx = 0, y = 0;
    for(auto i : g[x]) { 
        if(chk[i.fi]) continue;
        csz += sz[i.fi];
        if(sz[i.fi] > mx) {
            mx = sz[i.fi];
            y = i.fi;
        }
    }
    if(mx <= csz / 2) return x;
    sz[x] = csz - mx;
    return find_cen(y);
}

void ndfs(int x, int pa, int v, int k) {
    sub[v][k].push(dist(x, v));
    for(auto i : g[x]) {
        if(i.fi == pa) continue;
        if(chk[i.fi]) continue;
        ndfs(i.fi, x, v, k);
    }
}

int make_ct(int x) {
    x = find_cen(x);
    chk[x] = true;
    sub[x].resize(g[x].size());
    for(int i = 0; i < g[x].size(); i++) {
        if(chk[g[x][i].fi]) continue;
        ndfs(g[x][i].fi, x, x, i);
        submx[x].push(sub[x][i].top());
        int y = make_ct(g[x][i].fi);
        ctp[y] = x;
        ci[y] = i;
    }
    submx[x].push(0);
    st.push(submx[x].toptwo());
    return x;
}

int cnt = 0;
void update(int v) {
    c[v] = !c[v];

    st.pop(submx[v].toptwo());
    if(c[v]) submx[v].pop(0);
    else submx[v].push(0);
    st.push(submx[v].toptwo());

    int x = ctp[v];
    int pre = ci[v];
    while(x != 0) {
        cnt++;
        int temp = dist(x, v);
        st.pop(submx[x].toptwo());
        submx[x].pop(sub[x][pre].top());

        if(c[v]) sub[x][pre].pop(temp);
        else sub[x][pre].push(temp);

        submx[x].push(sub[x][pre].top());
        st.push(submx[x].toptwo());
        pre = ci[x];
        x = ctp[x];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    dfs(1, 0);
    crt = make_ct(1);

    int q;
    cin >> q;
    while(q--) {
        int t, v;
        cin >> t;
        if(t == 1) {
            cin >> v;
            update(v);
        }
        else cout << st.top() << '\n';
    }
}