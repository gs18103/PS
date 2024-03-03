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

const int MAX = 1010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

ll c[MAX][MAX], s[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int m, n, a, b;
    cin >> m >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if(c[i][j] == -1) c[i][j] = INF;
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + c[i][j];
        }
    }
    ll ans = INF;
    for(int i = b; i <= n; i++) {
        for(int j = a; j <= m; j++) {
            ans = min(ans, s[i][j] - s[i-b][j] - s[i][j-a] + s[i-b][j-a]);
        }
    }
    cout << ans;
}