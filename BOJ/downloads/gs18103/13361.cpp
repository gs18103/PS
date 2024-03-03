#include <bits/stdc++.h>

using namespace std;

map <int, vector <int> > g;
map <int, bool> chk;

bool flag;
int mx;
long long dfs(int x, int pa) {
    chk[x] = true;
    mx = max(mx, x);
    long long ret = x;
    for(auto i : g[x]) {
        if(i == pa) continue;
        if(!chk[i]) ret += dfs(i, x);
        else flag = true;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    long long ans = 0;
    vector <int> node;
    for(int i = 1; i <= n; i++) {
        int s, t;
        cin >> s >> t;
        node.emplace_back(s);
        node.emplace_back(t);
        chk[s] = chk[t] = false;
        ans += s + t;
        g[s].emplace_back(t), g[t].emplace_back(s);
    }
    for(auto i : node) {
        if(!chk[i]) {
            mx = 0;
            flag = false;
            ans -= dfs(i, 0);
            if(!flag) ans += mx;
        }
    }
    cout << ans;
}