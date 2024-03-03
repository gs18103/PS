#include <bits/stdc++.h>
#define g(tp, x) get<x>(tp)
#define LINF 1e18

using namespace std;
typedef long long ll;
typedef tuple <int, int, int> tp3;

int x[303], idx;
int n, m, mis = 0;
ll dp[2][303][303][303];
bool chk[2][303][303][303];

ll f(int s, int i, int j, int k) {
	if(i < 0 || j > n) return LINF;
	if(i == 0 && j == n) return 0;
	if(k == 0) return 0;
	if(chk[s][i][j][k]) return dp[s][i][j][k];
	chk[s][i][j][k] = true;
	if(s) dp[s][i][j][k] = min(f(0, i-1, j, k-1)+k*(x[j]-x[i-1]), f(1, i, j+1, k-1)+k*(x[j+1]-x[j]));
	else dp[s][i][j][k] = min(f(0, i-1, j, k-1)+k*(x[i]-x[i-1]), f(1, i, j+1, k-1)+k*(x[j+1]-x[i]));
	return dp[s][i][j][k];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	ll add = 0;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
		if(x[i] == 0) add += m, mis++, x[i] = 1010101;
	}
	x[0] = 0;
	sort(x, x+n+1);
	n -= mis;
	for(int i = 0; i <= n; i++) {
		if(x[i] == 0) idx = i;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, m * i - f(0, idx, idx, i));
	}
	cout << ans + add;
}