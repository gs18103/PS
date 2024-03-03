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

const int MAX = 101010;
const int INF = (1 << 30) - 1;
const ll LINF = 1LL << 60;

vector <int> g[MAX];
set <int> s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    for(int i = 1; i <= n; i++) {
        s.insert(i);
        sort(all(g[i]));
    }
    int cnt = 0;
    vector <int> ans;
    for(int i = 1; i <= n; i++) {
        if(s.find(i) != s.end()) {
            s.erase(i);
            int temp = 0;
            queue <int> q;
            q.em(i);
            while(!q.empty()) {
                int x = q.front(), idx = 0;
                q.pop();
                temp++;
                vector <int> nxt;
                for(auto it = s.begin(); it != s.end(); it++) {
                    while(idx < g[x].size() && s.find(g[x][idx]) == s.end()) idx++;
                    if(idx < g[x].size() && g[x][idx] == *it) {
                        idx++;
                        continue;
                    }
                    nxt.eb(*it);
                }
                for(auto j : nxt) {
                    q.em(j);
                    s.erase(j);
                }
            }
            ans.eb(temp);
            cnt++;
        }
    }
    cout << cnt << '\n';
    sort(all(ans));
    for(auto i : ans) cout << i << ' ';
}