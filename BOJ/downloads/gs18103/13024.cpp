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
const ll mod = 1e9+7;

ll dp[MAX], ans[MAX];
vector <int> g[MAX];

ll inv(ll a) {
    ll r = 1, b = mod - 2;
    while(b) {
        if(b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

void dfs1(int x, int pa) {
    dp[x] = 1;
    for(auto i : g[x]) {
        if(i == pa) continue;
        dfs1(i, x);
        dp[x] = (dp[x] * (dp[i] + 1)) % mod;
    }
}

void dfs2(int x, int pa) {
    ans[x] = dp[x];
    ll val;
    for(auto i : g[x]) {
        if(i == pa) continue;
        dp[x] = (dp[x] * inv(dp[i] + 1)) % mod;
        val = dp[i];
        dp[i] = (dp[i] * (dp[x] + 1)) % mod;
        dfs2(i, x);
        dp[i] = val;
        dp[x] = (dp[x] * (dp[i] + 1)) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        sum = (sum + ans[i]) % mod;
    }
    cout << sum;
}