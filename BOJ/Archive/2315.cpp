#include <bits/stdc++.h>
#define LINF 1000000000000000000LL

using namespace std;

int d[1010], n, m;
long long w[1010], dp[1010][1010][2], sum[1010][1010];
bool chk[1010][1010][2];

long long f(int l, int r, int b) {
	if(l < 1 || r > n) return LINF;
	if(l == 1 && r == n) return 0;
	if(chk[l][r][b]) return dp[l][r][b];
	chk[l][r][b] = true;
	dp[l][r][b] = LINF;
	if(b == 0) {
		dp[l][r][b] = min(dp[l][r][b], f(l-1, r, 0) + (d[l]-d[l-1])*(sum[1][l-1]+sum[r+1][n]));
		dp[l][r][b] = min(dp[l][r][b], f(l, r+1, 1) + (d[r+1]-d[l])*(sum[1][l-1]+sum[r+1][n]));
	}
	else {
		dp[l][r][b] = min(dp[l][r][b], f(l-1, r, 0) + (d[r]-d[l-1])*(sum[1][l-1]+sum[r+1][n]));
		dp[l][r][b] = min(dp[l][r][b], f(l, r+1, 1) + (d[r+1]-d[r])*(sum[1][l-1]+sum[r+1][n]));
	}
	return dp[l][r][b];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> d[i] >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			sum[i][j] = sum[i][j-1] + w[j];
		}
	}
	cout << f(m, m, 0);
}