#include <bits/stdc++.h>

using namespace std;

double C[1010][1010], dp[505][505];
bool chk[505][505];
int n, d, r;

double f(int i, int j) {
	if(j < 0) return 0.0;
	if(i <= r) return (i + j) * C[i+j-1][j];
	if(chk[i][j]) return dp[i][j];
	chk[i][j] = true;
	dp[i][j] = r * C[i+j-1][j];
	for(int k = 0; k <= i; k++) {
		dp[i][j] += C[i][k] * f(i - k, j - i + k);
	}
	return dp[i][j];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout << fixed; cout.precision(6);

	cin >> n >> d >> r;
	C[0][0] = 1.0;
	for(int i = 1; i <= n + d - 1; i++) {
		C[i][0] = 1.0;
		for(int j = 1; j <= i; j++) {
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	double ans = f(n, d);
	cout << ans / C[n+d-1][d];
}