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

vector <int> g[MAX];
int d[MAX], idx[MAX], cnt[MAX];

void dfs(int x, int pa) {
    d[x] = d[pa] + 1;
    for(auto i : g[x]) {
        if(i == pa) continue;
        dfs(i, x);
    }
}

int ndfs(int x, int pa) {
    int mx = 0;
    for(auto i : g[x]) {
        if(i == pa) continue;
        int temp = ndfs(i, x);
        mx = max(mx, temp);
        cnt[temp]++;
    }
    if(pa != 0) cnt[mx]--;
    return mx + 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, l;
    cin >> n >> l;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    if(l == 0) return !(cout << 0);
    
    int d1 = 0, d2 = 0, ans = 0;
    dfs(1, 0);
    for(int i = 1; i <= n; i++) {
        idx[i] = i;
        if(d[d1] < d[i]) d1 = i;
    }
    ndfs(d1, 0);
    l = 2 * l - 1;
    for(int i = n; i >= 1; i--) {
        if(cnt[i] <= l) ans += i * cnt[i], l -= cnt[i];
        else {
            ans += i * l;
            break;
        }
    }
    cout << ans + 1;
}