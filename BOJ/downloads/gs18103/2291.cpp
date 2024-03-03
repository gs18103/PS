#include <bits/stdc++.h>

using namespace std;

long long dp[11][222][222];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m, K;
	cin >> n >> m >> K;
	for(int i = 1; i <= m; i++) {
		dp[1][i][i] = 1;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int k = 1; k <= m; k++) {
				for(int l = 1; l <= k && j + l <= m; l++) {
					dp[i+1][j+l][l] += dp[i][j][k];
				}
			}
		}
	}
	vector <int> ans;
	int s = 1;
	for(int i = n; i > 0; i--) {
		long long sum = 0;
		for(int j = s; j <= m; j++) {
			if(sum + dp[i][m][j] >= K) {
				K -= sum;
				m -= j;
				s = j;
				ans.push_back(j);
				break;
			}
			sum += dp[i][m][j];
		}
	}
	for(auto i : ans) cout << i << ' ';
}