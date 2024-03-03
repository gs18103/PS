#include <bits/stdc++.h>

using namespace std;

int ind[101010];
vector <int> g[101010], gg[101010];
bool chk[101010];

void dfs(int x) {
    chk[x] = true;
    for(auto i : g[x]) {
        if(!chk[i]) dfs(i);
    }
}
void ndfs(int x) {
    chk[x] = true;
    for(auto i : g[x]) {
        if(!chk[i]) ndfs(i);
    }
    for(auto i : gg[x]) {
        if(!chk[i]) ndfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) ind[i] = 0, g[i].clear(), gg[i].clear(), chk[i] = false;
        for(int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            g[u].emplace_back(v), ind[v]++;
            gg[v].emplace_back(u);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(ind[i] == 0) dfs(i), ans++;
        }
        for(int i = 1; i <= n; i++) {
            if(!chk[i]) ndfs(i), ans++;
        }
        cout << ans << '\n';
    }
}