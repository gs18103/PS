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

const int MAX = 1010101;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

vector <int> rg[MAX];
bool chk[MAX], szu[MAX], flag, vis[MAX];
int rind[MAX], d[MAX], cnt;

void dfs(int x) {
    vis[x] = true;
    chk[x] = true;
    for(auto i : rg[x]) {
        if(!vis[i]) dfs(i);
        else if(chk[i]) szu[x] = true, flag = true;
    }
    chk[x] = false;
}

void dfs2(int x) {
    szu[x] = true;
    chk[x] = true;
    for(auto i : rg[x]) {
        if(!chk[i]) dfs2(i);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("pro10.in", "r", stdin);

    int n, m;
    cin >> n >> m;
    n++;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        rg[v].eb(u);
        rind[u]++;
    }
    for(int i = 1; i <= n; i++) {
        for(int j : rg[i]) {
            if(j == i) rind[i]--;
        }
    }
    queue <int> q;
    for(int i = 1; i < n; i++) if(rind[i] == 0) q.em(i);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto i : rg[x]) {
            if(i == x) continue;
            rind[i]--;
            if(rind[i] == 0 && i != n) {
                q.em(i);
            }
        }
    }
    q.em(n);
    d[n] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto i : rg[x]) {
            rind[i]--;
            d[i] += d[x];
            if(d[i] > 36500) d[i] = 36501;
            if(rind[i] == 0) {
                q.em(i);
            }
        }
    }

    dfs(n);
    if(flag) {
        int cnt = 0;
        cout << "zawsze\n";
        for(int i = 1; i < n; i++) if(szu[i] && !chk[i]) dfs2(i);
        for(int i = 1; i < n; i++) if(szu[i] || d[i] > 36500) cnt++;
        cout << cnt << '\n';
        for(int i = 1; i < n; i++) if(szu[i] || d[i] > 36500) cout << i << ' ';
        return 0;
    }
    int mx = 0; cnt = 0;
    for(int i = 1; i < n; i++) {
        if(d[i] > mx) {
            mx = d[i];
            cnt = 0;
        }
        if(d[i] == mx) cnt++;
    }
    if(mx > 36500) cout << "zawsze" << '\n';
    else cout << mx << '\n';
    cout << cnt << '\n';
    for(int i = 1; i < n; i++) {
        if(d[i] == mx) cout << i << ' ';
    }
}