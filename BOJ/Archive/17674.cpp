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
const int INF = 1e9;
const ll LINF = 1e18;

vector <pair <int, pll> > g[2*MAX];
ll d[2*MAX], sum, ans[2*MAX], up[2*MAX];
bool chk[2*MAX];
int deg[2*MAX];

void dfs(int x, int pa) {
    for(auto i : g[x]) {
        if(i.fi == pa) continue;
        d[i.fi] = d[x] + i.se.fi;
        up[i.fi] = up[x] + i.se.se;
        sum += i.se.fi;
        dfs(i.fi, x);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; ll c, d;
        cin >> u >> v >> c >> d;
        g[u].eb(v, make_pair(c, d)), g[v].eb(u, make_pair(d, c));
        deg[u]++, deg[v]++;
    }
    priority_queue <pll, vector <pll>, greater <pll> > pq;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1) pq.em(g[i][0].se.se, i);
    }
    while(pq.size() > 2) {
        pll cur = pq.top();
        pq.pop();
        chk[cur.se] = true;
        int u;
        for(auto i : g[cur.se]) {
            if(!chk[i.fi]) {
                u = i.fi;
                break;
            }
        }
        deg[u]--;
        if(deg[u] == 1) {
            for(auto i : g[u]) {
                if(!chk[i.fi]) {
                    pq.em(cur.fi + i.se.se, u);
                    break;
                }
            }
            continue;
        }
        ans[pq.size()] = ans[pq.size()+1] + cur.fi;
    }
    dfs(1, 0);
    ans[1] = LINF;
    for(int i = 1; i <= n; i++) {
        ans[1] = min(ans[1], sum - d[i] + up[i]);
    }
    
    int q;
    cin >> q;
    while(q--) {
        int u; cin >> u;
        cout << ans[u] << '\n';
    }
}