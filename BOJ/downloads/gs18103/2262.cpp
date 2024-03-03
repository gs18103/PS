#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

int r[300];
int dp[303][303], w[303][303];
bool chk[303][303];

int f(int i, int j) {
	if(i == j) return 0;
	if(chk[i][j]) return dp[i][j];
	chk[i][j] = true;
	dp[i][j] = INF;
	for(int k = i; k < j; k++) {
		dp[i][j] = min(dp[i][j], f(i, k) + f(k + 1, j) + abs(w[i][k] - w[k+1][j]));
	}
	return dp[i][j];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> r[i];
	}
	for(int i = 1; i <= n; i++) {
		w[i][i] = r[i];
		for(int j = i + 1; j <= n; j++) {
			w[i][j] = min(w[i][j-1], r[j]);
		}
	}
	cout << f(1, n);
}