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

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> g[MAX], r;
int pa[2][MAX], d[2][MAX], p[2], cutd[2][MAX], cutmx[2];

void dfs(int x, int t) {
    d[t][x] = 1;
    for(int i : g[x]) {
        if(i == pa[t][x]) continue;
        pa[t][i] = x;
        dfs(i, t);
        d[t][x] = max(d[t][x], d[t][i] + 1);
    }
}

int f(int p, int q, int r) {
    if(p == q) return INF;
    int ans = -f(q, p+(r?-1:1), r^1);
    cutmx[r^1] = max({cutmx[r^1], cutd[r^1][p+(r?-1:1)], cutd[r^1][q]});
    ans = max(ans, cutd[r][p] - cutmx[r^1]);
    //cout << p << ' ' << q << ' ' << r << ' ' << ans << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n >> p[0] >> p[1];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    dfs(p[0], 0), dfs(p[1], 1);
    int x = p[0];
    while(x != p[1]) {
        r.eb(x);
        x = pa[1][x];
    }
    r.eb(p[1]);

    cutd[0][0] = cutd[1][r.size()-1] = 1;
    for(int i = 0; i + 1 < r.size(); i++) {
        cutd[0][i] = i + 1;
        int x = r[i], y = r[i+1];
        for(int j : g[x]) {
            if(j == pa[0][x]) continue;
            if(j == y) continue;
            cutd[0][i] = max(cutd[0][i], d[0][j] + i + 1);
        }
    }
    for(int i = r.size() - 1; i > 0; i--) {
        cutd[1][i] = r.size() - i;
        int x = r[i], y = r[i-1];
        for(int j : g[x]) {
            if(j == pa[1][x]) continue;
            if(j == y) continue;
            cutd[1][i] = max(cutd[1][i], d[1][j] + (int)r.size() - i);
        }
    }
    cout << f(0, r.size()-1, 0);
}