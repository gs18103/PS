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

vector <int> g[3*MAX], sz[MAX];
map <int, int> Q[3*MAX];

void dfs(int x, int pa) {
    for(int i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
    }
    for(pii i : Q[x]) {
        if(Q[pa].find(i.fi) == Q[pa].end()) {
            sz[i.fi].eb(i.se + 1);
        }
        else {
            Q[pa][i.fi] += i.se + 1;
        }
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

    int q;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            Q[x].em(i, 0);
        }
    }
    dfs(1, 0);
    for(int i = 1; i <= q; i++) {
        ll ans = 0;
        for(int j : sz[i]) {
            ans += 1LL * j * (j - 1) / 2;
        }
        cout << ans << '\n';
    }
}