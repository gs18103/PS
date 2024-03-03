#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <set <int> > g(n+1);
    vector <bool> chk(n+1);
    vector <int> pre(n+1), nxt(n+1);
    for(int i = 0; i < n + m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].em(v), g[v].em(u);
    }
    for(int i = 1; i <= n; i++) {
        if(g[i].size() == 2) {
            int l = *g[i].begin(), r = *g[i].rbegin();
            g[r].erase(i), g[l].erase(i);
            chk[i] = true;
            pre[i] = l, pre[r] = i;
            nxt[l] = i, nxt[i] = r;
            while(l != r) {
                if(g[l].size() == 1) {
                    int x = *g[l].begin();
                    g[l].erase(x);
                    g[x].erase(l);
                    pre[l] = x;
                    nxt[x] = l;
                    l = x;
                }
                else if(g[r].size() == 1) {
                    int x = *g[r].begin();
                    g[r].erase(x);
                    g[x].erase(r);
                    nxt[r] = x;
                    pre[x] = r;
                    r = x;
                }
                else if(g[l].find(r) != g[l].end()) {
                    g[l].erase(r), g[r].erase(l);
                }
                else break;
            }
        }
    }
    if(nxt[1] < pre[1]) {
        int x = nxt[1];
        cout << 1 << ' ';
        while(x != 1) {
            cout << x << ' ';
            x = nxt[x];
        }
        cout << '\n';
    }
    else {
        int x = pre[1];
        cout << 1 << ' ';
        while(x != 1) {
            cout << x << ' ';
            x = pre[x];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}