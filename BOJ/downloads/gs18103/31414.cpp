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
typedef pair <int, ll> pil;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> g[MAX];
int c[MAX];
bool chk[MAX];

void dfs(int x) {
    chk[x] = true;
    for(int i : g[x]) {
        if(chk[i]) continue;
        c[i] = 1 - c[x];
        dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    set <pii> st;
    for(int i = 1; i <= n; i++) {
        int u; cin >> u;
        g[u].eb(i), g[i].eb(u);
        st.em(min(i, u), max(i, u));
    }
    
    for(int i = 1; i <= n; i++) {
        if(!chk[i]) {
            dfs(i);
        }
    }

    int ans = 0;
    for(pii x : st) {
        if(c[x.fi] != c[x.se]) ans++;
    }
    cout << ans << endl;
}