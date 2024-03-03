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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

struct DSU {
    vector <vector <pii> > p;
    int sz;
    void Init(int n, int m) {
        p.resize(n+1);
        p[0].resize(1);
        for(int i = 1; i <= n; i++) {
            p[i].resize(m+1);
            for(int j = 1; j <= m; j++) {
                p[i][j] = {i, j};
            }
        }
        sz = n * m;
    }

    pii find(pii x) {
        return p[x.fi][x.se] == x ? x : p[x.fi][x.se] = find(p[x.fi][x.se]);
    }
    void uni(pii x, pii y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(x > y) swap(x, y);
        p[y.fi][y.se] = x;
        sz--;
    }
} uft;

pii p1[10101], p2[10101];
vector <pii> c[10101];
int ans[10101];

int num[1010][1010];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= q; i++) {
        cin >> p1[i].fi >> p1[i].se >> p2[i].fi >> p2[i].se;
        for(int j = p1[i].fi; j <= p2[i].fi; j++) {
            for(int k = p1[i].se; k <= p2[i].se; k++) {
                if(!num[j][k]) num[j][k] = i;
            }
        }
    }

    uft.Init(n, m);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(num[i][j]) {
                uft.uni({0, 0}, {i, j});
                c[num[i][j]].eb(i, j);
            }
            else {
                for(int k = 0; k < 2; k++) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
                    if(!num[tx][ty]) uft.uni({i, j}, {tx, ty});
                }
            }
        }
    }

    ans[q] = uft.sz;

    for(int i = q; i > 1; i--) {
        for(pii x : c[i]) {
            uft.p[x.fi][x.se] = x;
            uft.sz++;
        }
        for(pii x : c[i]) {
            for(int j = 0; j < 4; j++) {
                int tx = x.fi + dx[j], ty = x.se + dy[j];
                if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
                if(num[tx][ty] >= i || num[tx][ty] == 0) uft.uni({tx, ty}, {x.fi, x.se});
            }
        }
        ans[i-1] = uft.sz;
    }
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}