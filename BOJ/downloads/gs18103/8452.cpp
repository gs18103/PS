#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace

using namespace std;
typedef pair <int, int> pii;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector <pii> E(m+1);
    for(int i = 1; i <= m; i++) {
        cin >> E[i].fi >> E[i].se;
    }
    
    vector <int> Q(q);
    vector <bool> chk(m+1);
    for(int i = 0; i < q; i++) {
        string s;
        cin >> s >> Q[i];
        if(s == "E") Q[i] = -Q[i];
        else chk[Q[i]] = true;
    }
    
    vector <int> d(n+1, 1e9);
    vector <vector <int>> g(n+1);
    for(int i = 1; i <= m; i++) {
        if(chk[i]) continue;
        g[E[i].fi].eb(E[i].se);
    }
    vector <int> ans;
    queue <int> que;
    d[1] = 0;
    auto bfs = [&](int st = 1) {
        que.em(st);
        while(!que.empty()) {
            int x = que.front();
            que.pop();
            for(int i : g[x]) {
                if(d[i] <= d[x] + 1) continue;
                d[i] = d[x] + 1;
                que.em(i);
            }
        }
    };
    bfs();
    for(int i = q - 1; i >= 0; i--) {
        if(Q[i] < 0) {
            if(d[-Q[i]] == (int)1e9) ans.eb(-1);
            else ans.eb(d[-Q[i]]);
        }
        else {
            int u = E[Q[i]].fi, v = E[Q[i]].se;
            g[u].eb(v);
            if(d[v] > d[u] + 1) bfs(u);
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i : ans) cout << i << '\n';
}