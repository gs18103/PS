#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll arr[5050], OR[5050][5050], dp[5050][5050];

void dnc(int t, int s, int e, int l, int r) {
	int m = s + e >> 1;
	int idx = m - 1;
	dp[t][m] = dp[t-1][m-1] + OR[m][m];
	for(int i = l; i <= min(m-1, r); i++) {
		if(dp[t][m] < dp[t-1][i] + OR[i+1][m]) {
			dp[t][m] = dp[t-1][i] + OR[i+1][m];
			idx = i;
		}
	}
	if(s == e) return;
	dnc(t, s, m, l, idx);
	dnc(t, m+1, e, idx, r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			OR[i][j] = OR[i][j-1] | arr[j];
		}
	}

	for(int i = 1; i <= n; i++) {
		dp[1][i] = OR[1][i];
	}

	for(int i = 2; i <= k; i++) {
		dnc(i, 1, n, 1, n);
	}
	cout << dp[k][n];
}