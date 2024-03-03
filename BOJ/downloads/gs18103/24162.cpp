#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

pll p[101];
pair <pii, int> E[10101];
vector <pii> g[10101];
vector <int> v[101];
int d[10101];
bool chk[10101];

ll dist(pll a, pll b) {
    return (b.fi - a.fi) * (b.fi - a.fi) + (b.se - a.se) * (b.se - a.se);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> p[i].fi >> p[i].se;
    }
    for(int i = 1; i <= m; i++) {
        cin >> E[i].fi.fi >> E[i].fi.se >> E[i].se;
        E[i+m] = E[i];
        swap(E[i+m].fi.fi, E[i+m].fi.se);
        v[E[i].fi.fi].eb(i);
        v[E[i].fi.se].eb(i+m);
    }

    for(int i = 1; i <= 2*m; i++) {
        int a = E[i].fi.fi, b = E[i].fi.se;
        for(int j : v[b]) {
            if(j % m == i % m) continue;
            if(dist(p[a], p[b]) + dist(p[b], p[E[j].fi.se]) > dist(p[a], p[E[j].fi.se])) continue;
            g[i].eb(j, E[j].se);
        }
    }

    for(int i = 1; i <= 2*m; i++) {
        d[i] = INF;
    }
    priority_queue <pii, vector <pii>, greater <pii>> pq;
    for(int i : v[1]) {
        d[i] = E[i].se;
        pq.em(E[i].se, i);
    }

    while(!pq.empty()) {
        int x = pq.top().se;
        pq.pop();
        if(chk[x]) continue;
        chk[x] = true;
        for(pll i : g[x]) {
            int y = i.fi, val = i.se + d[x];
            if(d[y] > val) {
                d[y] = val;
                pq.em(d[y], y);
            }
        }
    }
    int ans = INF;
    for(int i = 1; i <= 2 * m; i++) {
        if(E[i].fi.se == 2) ans = min(ans, d[i]);
    }
    if(ans < INF) cout << ans;
    else cout << "-1";
}