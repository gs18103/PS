#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll dp[1<<10][10][101];
bool chk[1<<10][10][101];

ll f(int s, int x, int k) {
	if(k == n) {
		if((s+1) == (1<<10)) return 1;
		else return 0;
	}
	if(chk[s][x][k]) return dp[s][x][k];
	chk[s][x][k] = true;
	if(x > 0) dp[s][x][k] += f(s|(1<<(x-1)), x-1, k+1);
	if(x < 9) dp[s][x][k] += f(s|(1<<(x+1)), x+1, k+1);
	dp[s][x][k] %= 1000000000;
	return dp[s][x][k];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	ll ans = 0;
	for(int i = 1; i < 10; i++) {
		ans += f(1<<i, i, 1);
		ans %= 1000000000;
	}
	cout << ans;
}