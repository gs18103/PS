#include <bits/stdc++.h>

using namespace std;

string s;

bool chk[55][55];
int dp[55][55];

int f(int l, int r) {
	if(l == r) return 0;
	if(l + 1 == r) {
		if(s[l] == s[r]) return 0;
		else return 1;
	}
	if(chk[l][r]) return dp[l][r];
	chk[l][r] = true;
	dp[l][r] = 2000000000;
	if(s[l] == s[r]) dp[l][r] = min(dp[l][r], f(l+1, r-1));
	else dp[l][r] = min(dp[l][r], f(l+1, r-1) + 1);
	dp[l][r] = min(dp[l][r], f(l+1, r) + 1);
	dp[l][r] = min(dp[l][r], f(l, r-1) + 1);
	return dp[l][r];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;

	int ans = f(0, s.size()-1);
	for(int i = 0; i < s.size(); i++) {
		for(int j = 0; j < i; j++) {
			for(int i = 0; i < 55; i++) {
				for(int j = 0; j < 55; j++) {
					dp[i][j] = 0;
					chk[i][j] = false;
				}
			}
			swap(s[i], s[j]);
			ans = min(ans, f(0, s.size()-1) + 1);
			swap(s[i], s[j]);
		}
	}
	cout << ans;
}