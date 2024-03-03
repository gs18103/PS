#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[5050][5050], p[5050][5050], sum[5050], arr[5050];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum[i] = sum[i-1] + arr[i];
			p[i][i] = i;
		}
		for(int len = 1; len <= n; len++) {
			for(int i = 1; i + len <= n; i++) {
				int j = i + len;
				dp[i][j] = 1000000000000000000LL;
				for(int k = p[i][j-1]; k <= p[i+1][j]; k++) {
					if(dp[i][j] > dp[i][k] + dp[k+1][j]) {
						dp[i][j] = dp[i][k] + dp[k+1][j];
						p[i][j] = k;
					}
				}
				dp[i][j] += sum[j] - sum[i-1];
			}
		}
		cout << dp[1][n] << '\n';
	}
}