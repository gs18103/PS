#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int MAX = 1010;
const int INF = 1 << 29;
const ll LINF = 1LL << 60;

vector <pii> g[MAX];
vector <int> ans;
vector <vector <pii> > pre[2][MAX];
int dp[2][MAX][MAX], c[MAX], tdp[2][MAX];
int n, k;

void mrg(int x, int y, int cost) {
    for(int i = 0; i <= c[x] + c[y]; i++) {
        tdp[0][i] = tdp[1][i] = INF;
    }
    vector <pii> tv[2];
    tv[0].resize(c[x]+c[y]+1);
    tv[1].resize(c[x]+c[y]+1);
    for(int i = 0; i <= c[x]; i++) {
        for(int j = 0; j <= c[y]; j++) {
            int temp;
            temp = tdp[0][i+j];
            tdp[0][i+j] = min(tdp[0][i+j], dp[0][x][i] + dp[0][y][j] + cost);
            if(temp != tdp[0][i+j]) tv[0][i+j] = make_pair(0, j);
            temp = tdp[0][i+j];
            tdp[0][i+j] = min(tdp[0][i+j], dp[0][x][i] + dp[1][y][j]);
            if(temp != tdp[0][i+j]) tv[0][i+j] = make_pair(1, j);
            temp = tdp[1][i+j];
            tdp[1][i+j] = min(tdp[1][i+j], dp[1][x][i] + dp[1][y][j] + cost);
            if(temp != tdp[1][i+j]) tv[1][i+j] = make_pair(1, j);
            temp = tdp[1][i+j];
            tdp[1][i+j] = min(tdp[1][i+j], dp[1][x][i] + dp[0][y][j]);
            if(temp != tdp[1][i+j]) tv[1][i+j] = make_pair(0, j);
        }
    }
    for(int i = 0; i <= c[x] + c[y]; i++) {
        dp[0][x][i] = tdp[0][i];
        dp[1][x][i] = tdp[1][i];
    }
    pre[0][x].eb(tv[0]);
    pre[1][x].eb(tv[1]);
}

void dfs(int x, int pa) {
    c[x] = 1;
    for(int i = 2; i <= n; i++) {
        dp[0][x][i] = dp[1][x][i] = INF;
    }
    dp[0][x][1] = INF;
    dp[1][x][0] = INF;
    for(auto i : g[x]) {
        if(i.fi == pa) continue;
        dfs(i.fi, x);
        mrg(x, i.fi, i.se);
        c[x] += c[i.fi];
    }
}

void go(int x, int pa, int s, int val) {
    if(s) ans.eb(x);
    int idx = pre[s][x].size() - 1;
    for(int i = g[x].size() - 1; i >= 0; i--) {
        if(g[x][i].fi == pa) continue;
        go(g[x][i].fi, x, pre[s][x][idx][val].fi, pre[s][x][idx][val].se);
        val -= pre[s][x][idx][val].se;
        idx--;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w), g[v].eb(u, w);
    }
    dfs(1, 0);
    cout << min(dp[0][1][k], dp[1][1][k]) << endl;
    if(dp[0][1][k] < dp[1][1][k]) go(1, 0, 0, k);
    else go(1, 0, 1, k);
    sort(all(ans));
    for(auto i : ans) cout << i << ' ';
}