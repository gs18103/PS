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

vector <int> g[5*MAX], ng[5*MAX];
bool chk[5*MAX];
int ord[5*MAX], low[5*MAX], scc[5*MAX], num;
int ind[5*MAX], pre[5*MAX], sz, c[2][5*MAX];
int dp[2][5*MAX];
stack <int> stk;

void dfs(int x) {
    chk[x] = true;
    stk.em(x);
    ord[x] = low[x] = ++num;
    for(auto i : g[x]) {
        if(ord[i] == 0) {
            dfs(i);
            low[x] = min(low[x], low[i]);
        }
        else if(chk[i]) low[x] = min(low[x], ord[i]);
    }
    if(low[x] == ord[x]) {
        sz++;
        while(stk.top() != x) {
            scc[stk.top()] = sz;
            chk[stk.top()] = false;
            stk.pop();
            c[0][sz]++;
        }
        scc[x] = sz;
        chk[x] = false;
        c[0][sz]++;
        stk.pop();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v);
    }
    for(int i = 1; i <= n; i++) {
        if(ord[i] == 0) dfs(i);
    }
    for(int i = 1; i <= n; i++) {
        for(auto j : g[i]) {
            if(scc[i] != scc[j]) {
                ng[scc[i]].eb(scc[j]);
                ind[scc[j]]++;
            }
            else c[1][scc[i]]++;
        }
    }
    queue <int> q;
    for(int i = 1; i <= sz; i++) {
        if(ind[i] == 0) {
            q.em(i);
            dp[0][i] = c[0][i];
            dp[1][i] = c[1][i];
        }
    }
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto i : ng[x]) {
            dp[1][i] = max(dp[1][i], dp[1][x] + 1 + c[1][i]);
            dp[0][i] = max(dp[0][i], dp[0][x] + c[0][i]);
            ind[i]--;
            if(ind[i] == 0) q.em(i);
        }
    }

    int maxn = 0, maxm = 0, maxnm = 0;
    for(int i = 1; i <= sz; i++) {
        maxn = max(maxn, dp[0][i]);
        maxm = max(maxm, dp[1][i]);
        maxnm = max(maxnm, dp[0][i] + dp[1][i]);
    }
    cout << (maxn == n) << '\n' << (maxm == m) << '\n' << (maxnm == n + m) << endl;
}