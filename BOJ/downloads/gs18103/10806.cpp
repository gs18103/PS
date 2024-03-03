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

vector <int> g[MAX], stk, ng[MAX];
int ord[MAX], low[MAX], cnt, c, BCC[MAX], nBCC[MAX];

void dfs(int x, int pa) {
    low[x] = ord[x] = ++cnt;
    stk.eb(x);
    bool flag = false;
    for(auto i : g[x]) {
        if(i == pa && !flag) {
            flag = true;
            continue;
        }
        if(ord[i]) low[x] = min(low[x], ord[i]);
        else {
            dfs(i, x);
            low[x] = min(low[x], low[i]);
        }
    }
    if(low[x] == ord[x]) {
        c++;
        while(stk.back() != x) {
            BCC[stk.back()] = c;
            stk.pop_back();
        }
        BCC[x] = c;
        nBCC[c] = x;
        stk.pop_back();
    }
}

int nord[MAX], ncnt;
vector <int> lf;

void ndfs(int x, int pa) {
    nord[x] = ++ncnt;
    if(ng[x].size() == 1) lf.eb(x);
    for(auto i : ng[x]) {
        if(i == pa) continue;
        ndfs(i, x);
    }
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
    dfs(1, 0);
    for(int i = 1; i <= n; i++) {
        for(auto j : g[i]) {
            if(BCC[i] != BCC[j]) ng[BCC[i]].eb(BCC[j]);
        }
    }
    if(c == 1) {
        cout << 0 << '\n';
        return 0;
    }
    if(c == 2) {
        cout << 1 << '\n';
        cout << nBCC[1] << ' ' << nBCC[2] << '\n';
        return 0;
    }
    ndfs(1, 0);
    int ans = (lf.size() + 1) / 2, d = lf.size() / 2;
    cout << ans << '\n';
    for(int i = 0; i < ans; i++) {
        cout << nBCC[lf[i]] << ' ' << nBCC[lf[i+d]] << '\n';
    }
}