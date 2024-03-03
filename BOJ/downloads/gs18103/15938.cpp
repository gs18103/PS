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
const ll mod = 1e9+7;

pii jang[MAX];

ll dp[202][404][404];
bool chk[404][404];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);

    int xs, ys, xh, yh, n, t;
    cin >> xs >> ys >> t >> xh >> yh >> n;
    for(int i = 1; i <= n; i++) {
        cin >> jang[i].fi >> jang[i].se;
    }
    if(abs(xs - xh) + abs(ys - yh) > t) {
        cout << 0 << endl;
        return 0;
    }
    xh = xh - xs + 201;
    yh = yh - ys + 201;
    for(int i = 1; i <= n; i++) {
        jang[i].fi = jang[i].fi - xs + 201;
        jang[i].se = jang[i].se - ys + 201;
        if(jang[i].fi >= 1 && jang[i].fi <= 401 && jang[i].se >= 1 && jang[i].se <= 401) {
            chk[jang[i].fi][jang[i].se] = true;
        }
    }
    dp[0][201][201] = 1;
    for(int i = 1; i <= t; i++) {
        for(int j = 1; j <= 401; j++) {
            for(int k = 1; k <= 401; k++) {
                if(chk[j][k]) continue;
                if(j == xh && k == yh) {
                    dp[i][j][k] += dp[i-1][j][k];
                    dp[i][j][k] %= mod;
                }
                for(int l = 0; l < 4; l++) {
                    int nx = j + dx[l], ny = k + dy[l];
                    if(nx == xh && ny == yh) continue;
                    dp[i][j][k] += dp[i-1][nx][ny];
                    dp[i][j][k] %= mod;
                }
            }
        }
    }
    cout << dp[t][xh][yh] << endl;
}