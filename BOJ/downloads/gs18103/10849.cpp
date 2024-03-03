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

const int MAX = 20000;
const int INF = 1e9;
const ll LINF = 1e18;

int N, P, M, G, T;
vector <pii> g[MAX];
int p[16], t[16];
int d[16][MAX], dist[16][16];
int dp[2][16][1<<16];
bool vis[MAX], chk[2][16][1<<16];

void djikstra(int k) {
    for(int i = 0; i < N; i++) {
        d[k][i] = INF;
        vis[i] = false;
    }
    d[k][p[k]] = 0;
    priority_queue <pii, vector <pii>, greater <pii> > pq;
    pq.em(0, p[k]);
    while(!pq.empty()) {
        int x = pq.top().se;
        pq.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(pii i : g[x]) {
            int y = i.fi;
            if(d[k][y] > i.se + d[k][x]) {
                d[k][y] = i.se + d[k][x];
                pq.em(d[k][y], y);
            }
        }
    }
}

int f(int b, int x, int bit) {
    if(bit + 1 >> P & 1) return dist[x][0];
    if(chk[b][x][bit]) return dp[b][x][bit];
    chk[b][x][bit] = true;
    dp[b][x][bit] = INF;
    for(int i = 0; i < P; i++) {
        if(bit >> i & 1) continue;
        dp[b][x][bit] = min(dp[b][x][bit], dist[x][i] + f(b, i, bit | (1 << i)));
        if(b) dp[b][x][bit] = min(dp[b][x][bit], T + f(0, i, bit | (1 << i)));
    }
    return dp[b][x][bit];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> P >> M >> G >> T;
    P++;
    p[0] = 0, t[0] = 0;
    for(int i = 1; i < P; i++) {
        cin >> p[i] >> t[i];
        G -= t[i];
    }
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w), g[v].eb(u, w);
    }
    for(int i = 0; i < P; i++) {
        djikstra(i);
        for(int j = 0; j < P; j++) {
            dist[i][j] = d[i][p[j]];
        }
    }
    if(f(0, 0, 1) <= G) cout << "possible without taxi";
    else if(f(1, 0, 1) <= G) cout << "possible with taxi";
    else cout << "impossible";
}