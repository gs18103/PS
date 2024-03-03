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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> g[2*MAX];
int ans[2*MAX], deg[2*MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ans[i] = -1;
        int u;
        while(1) {
            cin >> u;
            if(u == 0) break;
            g[i].eb(u);
        }
    }

    queue <int> q;

    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int u;
        cin >> u;
        q.em(u);
        ans[u] = 0;
    }

    for(int t = 1; !q.empty(); t++) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            int x = q.front();
            q.pop();
            for(auto j : g[x]) {
                deg[j]++;
                if(ans[j] == -1 && deg[j] >= (g[j].size() + 1) / 2) {
                    ans[j] = t;
                    q.em(j);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}   