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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

int p[30][MAX];
vector <int> g[MAX];
bool chk[MAX];
int d[MAX];

void ndfs(int x, int td) {
    chk[x] = true;
    d[x] = td;
    for(auto i : g[x]) {
        if(chk[i]) continue;
        ndfs(i, td + 1);
    }
}

int move(int x, int m) {
    for(int i = 0; i < 30; i++) {
        if(m >> i & 1) x = p[i][x];
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[0][i];
        g[p[0][i]].eb(i);
    }
    ndfs(1, 0);
    for(int i = 1; i < 30; i++) {
        for(int j = 1; j <= n; j++) {
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }
    chk[1] = chk[p[0][1]];
    d[1] = d[p[0][1]] + 1;

    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            p[0][1] = x;
            if(x == 1) {
                chk[1] = true;
                d[1] = 1;
            }
            else {
                chk[1] = chk[x];
                if(chk[1]) d[1] = d[p[0][1]] + 1;
            }
        }
        if(t == 2) {
            int m, x;
            cin >> m >> x;
            
            if(chk[x] && d[x] < m) {
                m -= d[x];
                if(!chk[1]) cout << move(p[0][1], m - 1) << '\n';
                else if(m % d[1] == 0) cout << 1 << '\n';
                else cout << move(p[0][1], (m % d[1]) - 1) << '\n';
            }
            else cout << move(p[0][x], m - 1) << '\n';
        }
    }
}