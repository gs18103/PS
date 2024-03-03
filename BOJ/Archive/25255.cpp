#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> g[MAX];
int c[MAX];

bool dfs(int x) {
    bool ret = false;
    for(int i : g[x]) {
        if(!c[i]) {
            c[i] = 3 - c[x];
            ret = ret || dfs(i);
        }
        else if(c[i] + c[x] != 3) ret = true;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m;
    ll p;
    cin >> n >> m >> p;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    
    int cnt = -1;
    for(int i = 1; i <= n; i++) {
        if(!c[i]) {
            c[i] = 1;
            if(dfs(i)) return !(cout << "impossible");
            cnt++;
        }
    }
    ll ans = 1;
    while(cnt--) {
        ans = (ans * 2) % p;
    }
    cout << (ans + 1) % p;
}