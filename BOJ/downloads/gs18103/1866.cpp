#include <bits/stdc++.h>

using namespace std;

int arr[10101];
int dp[10101];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, tr, he, ans = 1000000000;
	cin >> n;
	for(int i = 1, u; i <= n; i++) {
		cin >> u;
		arr[u]++;
	}
	cin >> tr >> he;
	for(int i = 1; i <= 10000; i++) {
		for(int j = 1; j <= i; j++) {
			dp[i] += arr[j] * j * tr;
		}
		int lcnt = 0, rcnt = arr[i], add = he, mid = i;
		for(int j = i - 1; j >= 0; j--) {
			dp[i] = min(dp[i], dp[j] + add);
			lcnt += arr[j];
			add += (mid - j) * tr * arr[j];
			while(lcnt > rcnt) {
				add += rcnt * tr;
				add -= lcnt * tr;
				mid--;
				rcnt += arr[mid];
				lcnt -= arr[mid];
			}
		}
	}
	cout << dp[10000];
}