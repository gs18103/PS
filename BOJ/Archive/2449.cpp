#include <bits/stdc++.h>

using namespace std;

int arr[202];
int dp[202][202][22];
bool chk[202][202][22];

int f(int l, int r, int k) {
	if(l > r) return 0;
	if(l == r) {
		if(arr[l] == k) return 0;
		else return 1;
	}
	if(chk[l][r][k]) return dp[l][r][k];
	dp[l][r][k] = 200;
	chk[l][r][k] = true;
	for(int i = l; i <= r; i++) {
		int temp = i;
		while(i < r && arr[i] == arr[i+1]) i++;
		dp[l][r][k] = min(dp[l][r][k], f(l, temp-1, arr[i])+f(i+1, r, arr[i])+1-(arr[i]==k));
	}
	return dp[l][r][k];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int ans = n+1;
	for(int i = 1; i <= k; i++) {
		ans = min(ans, f(1, n, i));
	}
	cout << ans;
}