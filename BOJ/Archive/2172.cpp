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

int a[22][22];
int n, l;
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, -1, 0, 1, -1, 0, 1};
ll dp[11][22][22][22][22];
bool chk[11][22][22][22][22];

ll f(int k, int x1, int y1, int x2, int y2) {
    if(2 * k - 1 == l) {
        if(x1 == x2 && y1 == y2) return 1;
        else return 0;
    }
    if(2 * k == l) {
        for(int i = 0; i < 8; i++) {
            if(x1 + dx[i] == x2 && y1 + dy[i] == y2) return 1;
        }
        return 0;
    }
    if(chk[k][x1][y1][x2][y2]) return dp[k][x1][y1][x2][y2];
    chk[k][x1][y1][x2][y2] = true;
    for(int i = 0; i < 8; i++) {
        int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
        if(nx1 < 1 || nx1 > n || ny1 < 1 || ny1 > n) continue;
        for(int j = 0; j < 8; j++) {
            int nx2 = x2 + dx[j], ny2 = y2 + dy[j];
            if(nx2 < 1 || nx2 > n || ny2 < 1 || ny2 > n) continue;
            if(a[nx1][ny1] != a[nx2][ny2]) continue;
            dp[k][x1][y1][x2][y2] += f(k+1, nx1, ny1, nx2, ny2);
        }
    }
    return dp[k][x1][y1][x2][y2];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> l;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for(int x1 = 1; x1 <= n; x1++) {
        for(int y1 = 1; y1 <= n; y1++) {
            for(int x2 = 1; x2 <= n; x2++) {
                for(int y2 = 1; y2 <= n; y2++) {
                    if(a[x1][y1] != a[x2][y2]) continue;
                    ans += f(1, x1, y1, x2, y2);
                }
            }
        }
    }
    cout << ans;
}