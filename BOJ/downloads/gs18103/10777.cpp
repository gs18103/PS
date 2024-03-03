#include <bits/stdc++.h>

using namespace std;

long long a[3030], b[110];
int n, m;
long long dp[2][2][110][110];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	sort(b+1, b+m+1);

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			for(int k = m+1; k > j; k--) {
				if(i) dp[0][i%2][j][k] = max(dp[1][(i+1)%2][j][k], dp[0][(i+1)%2][j][k]);
				if(j) {
					dp[0][i%2][j][k] = max(dp[0][i%2][j-1][k], dp[0][i%2][j][k]);
					dp[0][i%2][j][k] = max(dp[1][i%2][j-1][k], dp[0][i%2][j][k]);
				}
				if(k <= m) {
					dp[0][i%2][j][k] = max(dp[0][i%2][j][k+1], dp[0][i%2][j][k]);
					dp[0][i%2][j][k] = max(dp[1][i%2][j][k+1], dp[0][i%2][j][k]);
				}
				if(i) dp[1][i%2][j][k] = dp[0][(i+1)%2][j][k] + a[i];
				if(j) {
					dp[1][i%2][j][k] = max(dp[0][i%2][j-1][k] + b[j], dp[1][i%2][j][k]);
				}
				if(k <= m) {
					dp[1][i%2][j][k] = max(dp[0][i%2][j][k+1] + b[k], dp[1][i%2][j][k]);
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i <= m; i++) {
		ans = max(ans, dp[0][n%2][i][i+1]);
		ans = max(ans, dp[1][n%2][i][i+1]);
	}
	cout << ans;
}