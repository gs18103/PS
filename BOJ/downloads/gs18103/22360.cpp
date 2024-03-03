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

const int MAX = 202020;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

vector <int> g[MAX];
map <pii, int> mp[MAX];
pii add[MAX];
string s;
ll ans = 0;

void dfs(int x, int pa) {
    for(auto i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
        if(mp[x].size() < mp[i].size()) {
            swap(mp[x], mp[i]);
            swap(add[x], add[i]);
        }
        for(auto j : mp[i]) {
            pii c = j.fi;
            c.fi += add[i].fi + add[x].fi;
            c.se += add[i].se + add[x].se;
            if(s[x] == 'U') c.fi -= 2, c.se--;
            if(s[x] == 'C') c.fi++;
            if(s[x] == 'P') c.se++;
            if(mp[x].find({-c.fi, -c.se}) != mp[x].end()) {
                ans += (ll)j.se * mp[x][{-c.fi, -c.se}];
            }
        }
        for(auto j : mp[i]) {
            pii c = j.fi;
            c.fi += add[i].fi - add[x].fi;
            c.se += add[i].se - add[x].se;
            mp[x][c] += j.se;
        }
    }
    mp[x][{-add[x].fi, -add[x].se}]++;
    if(s[x] == 'U') add[x].fi -= 2, add[x].se--;
    if(s[x] == 'C') add[x].fi++;
    if(s[x] == 'P') add[x].se++;
    if(mp[x].find({-add[x].fi, -add[x].se}) != mp[x].end()) {
        ans += mp[x][{-add[x].fi, -add[x].se}];
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }

    dfs(1, 0);
    cout << ans << endl;
}