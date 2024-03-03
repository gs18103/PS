#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define INF 2000000000;
#define LINF 1000000000000000000LL
#define mod 1000000007
 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
int r, c;
ll dp[3030][3030], fact[9090909], C[3030][3030];
 
ll f(int x, int y) {
	if(x > r || y > c) return 0;
	if(x == r && y == c) return 1;
	if(dp[x][y] != 0) return dp[x][y];
	dp[x][y] += (fact[x] * f(x, y+1)) % mod;
	dp[x][y] += (fact[y] * f(x+1, y)) % mod;
	dp[x][y] %= mod;
	return dp[x][y];
}
 
int main() {
	fastio;
	int n, mx = 0, my = 0, mix = 3030, miy = 3030;
	C[0][0] = 1;
	for(int i = 1; i <= 3000; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
	}
 
	cin >> r >> c >> n;
	fact[0] = 1;
	for(int i = 1; i <= r * c; i++) {
		fact[i] = (fact[i-1] * i) % mod;
	}
	for(int i = 1, x, y; i <= n; i++) {
		cin >> x >> y;
		mix = min(mix, x);
		mx = max(mx, x);
		miy = min(miy, y);
		my = max(my, y);
	}
	ll ans = (f(mx-mix+1, my-miy+1) * fact[(mx-mix+1)*(my-miy+1)-n]) % mod;
	ans = (ans * C[r-(mx-mix+1)][mix-1]) % mod;
	ans = (ans * C[c-(my-miy+1)][miy-1]) % mod;
	cout << ans;
}