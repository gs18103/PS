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

const int INF = 1e9;
const ll LINF = 1e18;

struct DSU {
    vector <int> p;
    DSU(int n) {
        p.resize(n);
        for(int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void uni(int x, int y) {
        x = find(x), y = find(y);
        p[y] = x;
    }
};

void dfs(int x, int pa, vector <vector <int>> &g, vector <int> &p, vector <int> &dep) {
    dep[x] = dep[pa] + 1;
    p[x] = pa;
    for(int i : g[x]) {
        if(i == pa) continue;
        dfs(i, x, g, p, dep);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector <vector <int>> g(n);
    set <pii> st;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
        g[u].eb(v), g[v].eb(u);
    }
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
        st.em(u, v);
    }

    vector <int> dep(n), p(n);
    dfs(0, -1, g, p, dep);

    DSU S(n);
    for(int i = 0; i < n; i++) {
        for(int j : g[i]) {
            if(i > j) continue;
            if(st.find(pii(i, j)) != st.end()) {
                if(p[i] == j) S.uni(j, i);
                else S.uni(i, j);
                st.erase(pii(i, j));
            }
        }
    }
    
    cout << st.size() << '\n';
    for(auto [u, v] : st) {
        int pu = S.find(u), pv = S.find(v);
        if(pu == pv) exit(1);
        if(dep[pu] < dep[pv]) swap(pu, pv), swap(u, v);
        cout << pu << ' ' << p[pu] << ' ' << u << ' ' << v << '\n';
        S.uni(v, u);
    }
}
