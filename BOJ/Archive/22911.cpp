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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

set <int> g[MAX];
int v[MAX], pre[MAX], sz[MAX];
ll dp[MAX], fact[MAX], inv[MAX];

void dfs(int x) {
    dp[x] = 1;
    sz[x] = 1;
    vector <int> tmp;
    for(int i : g[x]) {
        dfs(i);
        dp[x] *= dp[i];
        dp[x] %= mod;
        sz[x] += sz[i];
        tmp.eb(sz[i]);
    }
    dp[x] *= fact[sz[x]-1];
    dp[x] %= mod;
    for(int i : tmp) {
        dp[x] *= inv[i];
        dp[x] %= mod;
    }
}

ll mypow(ll a, ll b) {
    ll r = 1;
    while(b) {
        if(b & 1) r = r * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return r;
}

int solve() {
    int n;
    cin >> n;
    g[0].clear();
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        g[i].clear();
    }
    if(v[1] != 1) return 0;
    int cur = 1; pre[1] = 0;
    g[0].em(1);
    for(int i = 2; i <= n; i++) {
        if(v[i] > v[i-1] + 1) return 0;
        if(v[i] == v[i-1] + 1) {
            pre[i] = cur;
            g[cur].em(i);
            cur = i;
        }
        else {
            int k = v[i-1] - v[i];
            while(k--) {
                cur = pre[cur];
            }
            pre[i] = pre[cur];
            g[pre[cur]].em(i);
            g[pre[cur]].erase(cur);
            g[i].em(cur);
            cur = i;
        }
    }
    dfs(0);
    return dp[0];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int q;
    cin >> q;
    fact[0] = 1;
    for(int i = 1; i <= 100000; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    inv[100000] = mypow(fact[100000], mod - 2);
    for(int i = 100000; i > 0; i--) {
        inv[i-1] = inv[i] * i % mod;
    }
    for(int i = 1; i <= q; i++) {
        cout << "Case #" << i << ": ";
        cout << solve() << '\n';
    }
}