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

struct Query {
    int u, v, lb, ub, idx;
    Query(int u, int v, int lb, int ub, int idx) : u(u),v(v), lb(lb), ub(ub), idx(idx) {}
};

vector <Query> query;
vector <pii> g[MAX];
int d[MAX], p[MAX];

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(x > y) swap(x, y);
    p[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w), g[v].eb(u, w);
    }

    for(int i = 1; i <= n; i++) {
        d[i] = INF;
    }

    priority_queue <pii, vector <pii>, greater <pii> > pq;

    for(int i = 1; i <= k; i++) {
        int u;
        cin >> u;
        d[u] = 0;
        pq.em(0, u);
    }

    while(!pq.empty()) {
        int x = pq.top().se, td = pq.top().fi;
        pq.pop();
        if(d[x] < td) continue;
        for(auto i : g[x]) {
            int y =  i.fi, w = i.se;
            if(d[y] > d[x] + w) {
                d[y] = d[x] + w;
                pq.em(d[y], y);
            }
        }
    }

    for(int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        query.eb(u, v, 0, (int)1e8, i);
    }

    bool flag = false;
    while(!flag) {
        vector <pii> V;
        for(int i = 1; i <= n; i++) {
            V.eb(d[i], i);
            p[i] = i;
        }

        sort(all(query), [](Query a, Query b) {
            return a.lb + a.ub > b.lb + b.ub;
        });
        sort(all(V));

        int idx = n - 1;
        flag = true;
        for(auto &i : query) {
            if(i.lb == i.ub) continue;
            flag = false;
            int m = (i.lb + i.ub + 1) / 2;
            while(idx >= 0 && V[idx].fi >= m) {
                int x = V[idx].se;
                for(auto j : g[x]) {
                    if(d[j.fi] >= m) uni(j.fi, x);
                }
                idx--;
            }
            if(find(i.u) == find(i.v)) i.lb = m;
            else i.ub = m - 1;
        }
    }

    sort(all(query), [](Query a, Query b) {
        return a.idx < b.idx;
    });

    for(auto i : query) {
        cout << i.lb << '\n';
    }
}