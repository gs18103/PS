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

ll c[505][505], d[505][505];
bool chk[505][505];

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, -1, 0, 1, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if(c[i][j] == -1) c[i][j] = LINF;
            if(c[i][j] == -2) c[i][j] = 0;
            d[i][j] = LINF;
        }
    }
    priority_queue <pair <ll, pii>, vector <pair <ll, pii> >, greater <pair <ll, pii> > > pq;
    for(int i = 2; i <= m; i++) {
        d[1][i] = c[1][i];
        pq.em(c[1][i], make_pair(1, i));
    }
    for(int i = 2; i < n; i++) {
        d[i][m] = c[i][m];
        pq.em(c[i][m], make_pair(i, m));
    }
    while(!pq.empty()) {
        int x = pq.top().se.fi;
        int y = pq.top().se.se;
        pq.pop();
        if(chk[x][y]) continue;
        chk[x][y] = true;
        for(int i = 0; i < 8; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if(d[tx][ty] > d[x][y] + c[tx][ty]) {
                d[tx][ty] = d[x][y] + c[tx][ty];
                pq.em(d[tx][ty], make_pair(tx, ty));
            }
        }
    }

    ll ans = LINF;
    for(int i = 2; i <= n; i++) {
        ans = min(ans, d[i][1]);
    }
    for(int i = 2; i < m; i++) {
        ans = min(ans, d[n][i]);
    }
    if(ans == LINF) cout << -1;
    else cout << ans;
}