#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(X) memset(X, 0, sizeof(X))
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 808;
const int INF = 1e9;
const ll LINF = 1e18;

int residual[MAX][MAX];
vector <int> g[MAX];

bool visited[MAX];
int pre[MAX];


bool bfs(int source, int sink) {
    reset(visited);
    visited[source] = true;
    pre[source] = 0;
    queue <int> q;
    q.em(source);
    
    while(!q.empty()) {
        int curr = q.front(); 
        q.pop();
        for (auto next : g[curr]) {
            if (residual[curr][next] > 0 && visited[next] == false) {
                visited[next] = true;
                pre[next] = curr;
                q.em(next);
                if(next == sink) return true;
            }
        }
    }
    return false;
}

int Edmonds_Karp(int source, int sink) {
    int maxflow = 0;

    while(bfs(source, sink)) {
        int flowofpath = INF;
        int curr = sink;
        while(curr != source) {
            flowofpath = min(flowofpath, residual[pre[curr]][curr]);
            curr = pre[curr];
        }
        curr = sink;
        while(curr != source) {
            residual[pre[curr]][curr] -= flowofpath;
            residual[curr][pre[curr]] += flowofpath;
            curr = pre[curr];
        }
        maxflow += flowofpath;
    }
    return maxflow;
}

void solve() {
    int n, m; 
    cin >> n >> m;
    
    int source = n+1, sink = 2;
    reset(residual);
    for(int i = 1; i <= 2*n; i++) {
        g[i].clear();
    }
    for(int i = 1; i <= n; i++) {
        g[i].eb(i+n);
        g[i+n].eb(i);
        residual[i][i+n]++;
    }
    for(int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        g[u+n].eb(v);
        g[v].eb(u+n);
        g[v+n].eb(u);
        g[u].eb(v+n);
        residual[u+n][v]++;
        residual[v+n][u]++;
    }
    cout << Edmonds_Karp(source, sink) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    solve();
}
