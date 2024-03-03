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

int n, g[MAX][2], k[MAX][2];
vector <int> ng[2*MAX];
bool chk[2*MAX];
int tcnt;

void dfs(int x) {
    chk[x] = true;
    for(auto i : ng[x]) {
        if(i == x) tcnt++;
        if(chk[i]) continue;
        dfs(i);
    }
}

bool flag(int m) {
    for(int i = 1; i <= 2 * n; i++) {
        ng[i].clear(), chk[i] = false;
    }
    for(int i = 1; i <= n; i++) {
        if(k[i][0] > m && k[i][1] > m) return false;
        int u = 0, v = 0;
        if(k[i][0] <= m) u = g[i][0];
        if(k[i][1] <= m) v = g[i][1];
        if(u == 0) ng[v].eb(v);
        else if(v == 0) ng[u].eb(u);
        else ng[u].eb(v), ng[v].eb(u);
    }
    for(int i = 1; i <= 2 * n; i++) {
        if(!chk[i]) {
            tcnt = 0;
            dfs(i);
            if(tcnt > 1) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> g[i][0] >> k[i][0] >> g[i][1] >> k[i][1];
    }

    int lb = 0, ub = 1000000;
    while(lb < ub) {
        int m = lb + ub >> 1;
        if(flag(m)) ub = m;
        else lb = m + 1;
    }
    cout << lb;
}