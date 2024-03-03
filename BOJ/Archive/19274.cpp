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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> g[MAX];
int dp[MAX], L[MAX];

void dfs(int x, int pa) {
    if(g[x].size() == 1) return;
    int cnt = 0;
    for(int i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
        dp[x] += dp[i];
        if(dp[i] == 0) cnt++;
    }
    dp[x] += max(0, cnt - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        g[u].eb(v), g[v].eb(u);
    }

    for(int i = 1; i <= n; i++) {
        if(g[i].size() > 2) {
            dfs(i, 0);
            cout << dp[i];

            return 0;
        }
    }
    cout << 1;
}