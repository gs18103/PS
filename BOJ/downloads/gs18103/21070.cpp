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

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

vector <int> g[MAX], ng[MAX], v;
int ord[MAX], low[MAX], bcc[MAX], num, s;
bool chk[MAX];

void dfs(int x, int pa) {
    chk[x] = true;
    ord[x] = low[x] = ++num;
    bool flag = false;
    v.eb(x);
    for(int i : g[x]) {
        if(i == pa && !flag) {
            flag = true;
            continue;
        }
        if(chk[i]) low[x] = min(low[x], ord[i]);
        else {
            dfs(i, x);
            low[x] = min(low[x], low[i]);
        }
    }
    if(low[x] == ord[x]) {
        s++;
        while(v.back() != x) {
            bcc[v.back()] = s;
            v.pop_back();
        }
        bcc[v.back()] = s;
        v.pop_back();
    }
}

int d[MAX];

int ndfs(int x, int pa) {
    chk[x] = true;
    int ret = 0;
    int mx1 = 0, mx2 = 0;
    for(int i : ng[x]) {
        if(i == pa) continue;
        ret = max(ret, ndfs(i, x));
        if(d[i] + 1 > mx2) mx2 = d[i] + 1;
        if(mx2 > mx1) swap(mx1, mx2);
    }
    d[x] = mx1;
    return max(ret, mx1 + mx2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }

    for(int i = 0; i < n; i++) {
        if(!chk[i]) dfs(i, -1);
    }
    for(int i = 0; i < n; i++) {
        for(int j : g[i]) {
            if(bcc[i] != bcc[j]) {
                ng[bcc[i]].eb(bcc[j]);
            }
        }
    }


    for(int i = 1; i <= s; i++) chk[i] = false;

    int ans = -1;
    for(int i = 1; i <= s; i++) {
        if(!chk[i]) ans += ndfs(i, 0) + 1;
    }
    cout << ans;
}