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
const ll mod = 1e9;

vector <int> g[MAX], ng[MAX];
int ind[MAX];
ll dp[MAX];
bool chk[MAX];

bool tchk[MAX];

void dfs(int x) {
    tchk[x] = true;
    for(auto i : g[x]) {
        ng[x].eb(i);
        ind[i]++;
        if(tchk[i]) continue;
        dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
    }
    dfs(1);
    
    queue <int> q;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) q.em(i);
    }

    dp[1] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto i : ng[x]) {
            ind[i]--;
            dp[i] += dp[x];
            if(chk[x]) chk[i] = true;
            if(dp[i] >= mod) {
                dp[i] %= mod;
                chk[i] = true;
            }
            if(ind[i] == 0) {
                q.em(i);
            }
        }
    }
    
    if(ind[2] != 0) {
        cout << "inf";
        return 0;
    }
    if(chk[2]) {
        ll div = 100000000;
        for(int i = 8; i >= 0; i--) {
            cout << (dp[2] / div) % 10;
            div /= 10;
        }
    }
    else {
        cout << dp[2];
    }
}