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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 5050;
const int INF = 1e9;
const ll LINF = 1e18;

int chk[MAX], sz[MAX];
vector <int> g[MAX];
vector <pii> dp[MAX];
int ans[MAX][MAX];

void dfs(int x, int pa) {
    sz[x] = 1;
    for(auto i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
        sz[x] += sz[i];
    }

    dp[x].resize(2);
    dp[x][1] = {chk[x], chk[x]};
    vector <pii> temp;
    for(auto i : g[x]) {
        if(i == pa) continue;
        temp.resize(dp[x].size() + dp[i].size() - 1);
        for(int j = 1; j < temp.size(); j++) temp[j].fi = INF;
        for(int j = 1; j < dp[x].size(); j++) {
            for(int k = 0; k < dp[i].size(); k++) {
                temp[j+k].fi = min(temp[j+k].fi, dp[x][j].fi + dp[i][k].fi);
                temp[j+k].se = max(temp[j+k].se, dp[x][j].se + dp[i][k].se);
            }
        }
        dp[x] = temp;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, B;
    cin >> n >> B;
    for(int i = 0; i < B; i++) {
        int u; cin >> u;
        chk[u] = 1;
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < dp[i].size(); j++) {
            ans[j][dp[i][j].fi]++;
            ans[j][dp[i][j].se+1]--;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= B; j++) {
            ans[i][j] += ans[i][j-1];
        }
    }

    int q;
    cin >> q;
    int cnt = 0;
    while(q--) {
        int i, j;
        cin >> i >> j;
        if(ans[i][j] > 0) cnt++;
    }
    cout << cnt;
}