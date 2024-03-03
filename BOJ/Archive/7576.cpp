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

int a[1010][1010];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    queue <pii> q;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) q.em(i, j);
        }
    }
    while(!q.empty()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || nx > m || ny < 1 || ny > n || a[nx][ny] != 0) continue;
            q.em(nx, ny);
            a[nx][ny] = a[x][y] + 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            ans = max(ans, a[i][j] - 1);
            if(a[i][j] == 0) {
                return !(cout << -1);
            }
        }
    }
    cout << ans;
}