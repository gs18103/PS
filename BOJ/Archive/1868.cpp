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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> g[MAX];
int rnk[MAX];
int dp[MAX][20];

void dfs(int x, int pa) {
    for(auto i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
        for(int j = 0; j < 20; j++) {
            dp[x][j] += dp[i][j];
        }
    }
    for(int i = 19; i >= 0; i--) {
        if(dp[x][i] >= 2) {
            rnk[x] = i + 1;
            break;
        }
    }
    for(int i = rnk[x]; i < 20; i++) {
        if(dp[x][i] == 0) {
            rnk[x] = i;
            break;
        }
    }
    dp[x][rnk[x]]++;
    for(int i = 0; i < rnk[x]; i++) {
        dp[x][i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }

    dfs(1, 0);
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        mx = max(mx, rnk[i]);
    }
    cout << mx;
}