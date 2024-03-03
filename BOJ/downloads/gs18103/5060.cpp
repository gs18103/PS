#include <bits/stdc++.h>

using namespace std;

double arr[202];
double dp[202][202][202];
bool chk[202][202][202];

double f(int s, int e, int c) {
	if(chk[s][e][c]) return dp[s][e][c];
	chk[s][e][c] = true;
	if(c == 0) {
		double ret = 0;
		for(int i = s; i <= e; i++) {
			ret += abs(arr[s]+(arr[e]-arr[s])*(double)(i-s)/(double)(e-s)-arr[i]);
		}
		return dp[s][e][c] = ret;
	}
	dp[s][e][c] = 100000000.0;
	for(int i = s + 1; i < e; i++) {
		dp[s][e][c] = min(dp[s][e][c], f(s, i, 0) + f(i, e, c-1));
	}
	return dp[s][e][c];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout << fixed; cout.precision(5);
	int q;
	cin >> q;
	while(q--) {
		int h, c;
		cin >> h >> c;
		for(int i = 1; i <= h; i++) {
			cin >> arr[i];
		}
		for(int i = 1; i <= h; i++) {
			for(int j = 1; j <= h; j++) {
				for(int k = 0; k <= c; k++) {
					dp[i][j][k] = 0;
					chk[i][j][k] = false;
				}
			}
		}
		cout << f(1, h, c-2) / (double)h << '\n';
	}
}