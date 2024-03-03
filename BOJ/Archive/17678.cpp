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

const int MAX = 505050;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> g[MAX], s[MAX], ng[MAX];
vector <pii> E;
int num[MAX], low[MAX], cnt = 0, p[MAX], ans = 0;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void uni(int x, int y) {
    x = find(x), y = find(y);
    if(x > y) swap(x, y);
    p[y] = x;
}

void dfs(int x, int pa) {
    low[x] = num[x] = ++cnt;
    bool flag = false;
    for(auto i : g[x]) {
        if(i == pa && !flag) {
            flag = true;
            continue;
        }
        if(num[i] != 0) low[x] = min(low[x], num[i]);
        else if(num[i] == 0) {
            dfs(i, x);
            low[x] = min(low[x], low[i]);
        }
    }
    for(auto i : g[x]) {
        if(i == pa) continue;
        if(low[i] > num[x]) E.eb(i, x);
        else uni(i, x);
    }
}

void ndfs(int x, int pa) {
    int tcnt = 0;
    for(auto i : ng[x]) {
        if(i == pa) continue;
        ndfs(i, x);
        tcnt++;
    }
    if(tcnt == 0 && x != 1) ans++;
    if(tcnt == 1 && x == 1) ans++;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        int u; cin >> u;
        s[u].eb(i);
    }
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j < s[i].size(); j++) {
            g[s[i][j-1]].eb(s[i][j]);
            g[s[i][j]].eb(s[i][j-1]);
        }
    }
    dfs(1, 0);
    for(auto i : E) {
        ng[find(i.fi)].eb(find(i.se));
        ng[find(i.se)].eb(find(i.fi));
    }
    ndfs(1, 0);
    cout << (ans + 1) / 2;
}