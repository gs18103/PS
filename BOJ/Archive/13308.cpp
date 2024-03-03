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

const int MAX = 3030;
const int INF = 1e9;
const ll LINF = 1e18;

ll c[MAX];
int n, m;
vector <pair <int, ll> > g[MAX], ng[MAX];

void djikstra(int v) {
    vector <ll> d(n+1);
    vector <bool> chk(n+1);
    for(int i = 1; i <= n; i++) {
        d[i] = LINF;
    }
    d[v] = 0;
    priority_queue <pll, vector <pll>, greater <pll> > pq;
    pq.em(0, v);
    while(!pq.empty()) {
        int x = pq.top().se;
        pq.pop();
        if(chk[x]) continue;
        chk[x] = true;
        for(auto i : g[x]) {
            int y = i.fi;
            if(d[y] > d[x] + i.se) {
                d[y] = d[x] + i.se;
                pq.em(d[y], y);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(i == v) continue;
        ng[v].eb(i, c[v] * d[i]);
    }
}

void ndjikstra(int v) {
    vector <ll> d(n+1);
    vector <bool> chk(n+1);
    for(int i = 1; i <= n; i++) {
        d[i] = LINF;
    }
    d[v] = 0;
    priority_queue <pll, vector <pll>, greater <pll> > pq;
    pq.em(0, v);
    while(!pq.empty()) {
        int x = pq.top().se;
        pq.pop();
        if(chk[x]) continue;
        chk[x] = true;
        for(auto i : ng[x]) {
            int y = i.fi;
            if(d[y] > d[x] + i.se) {
                d[y] = d[x] + i.se;
                pq.em(d[y], y);
            }
        }
    }
    cout << d[n];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w), g[v].eb(u, w);
    }
    for(int i = 1; i <= n; i++) {
        djikstra(i);
    }
    ndjikstra(1);
}