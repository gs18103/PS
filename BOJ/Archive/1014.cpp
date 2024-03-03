#include <bits/stdc++.h>

using namespace std;

string arr[10];
int dp[10][1<<10];
bool chk[10][1<<10];
int n, m;

int f(int k, int s) {
	if(k == n) return 0;
	if(chk[k][s]) return dp[k][s];
	chk[k][s] = true;
	for(int i = 0; i < (1<<m); i++) {
		bool tchk[10], flag = false;
		int cnt = 0;
		for(int j = 0; j < m; j++) {
			tchk[j] = false;
			if((1<<j)&i) {
				tchk[j] = true, cnt++;
				if(j && tchk[j-1]) flag = true;
				if(j && ((s>>(j-1))&1)) flag = true;
				if(j+1 < m && ((s>>(j+1))&1)) flag = true;
				if(arr[k][j] == 'x') flag = true;
			}
		}
		if(flag) continue;
		dp[k][s] = max(dp[k][s], cnt + f(k+1, i));
	}
	return dp[k][s];
}

void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << f(0, 0) << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		memset(dp, 0, sizeof(dp));
		memset(chk, false, sizeof(chk));
		solve();
	}
}