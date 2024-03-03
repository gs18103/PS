#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sum[101010], dp[2][101010];
int n, k;
int pre[202][101010];

void dnc(int t, int s, int e, int l, int r) {
	int m = s + e >> 1;
	int idx;
	dp[t%2][m] = 0;
	for(int i = min(m-1, r); i >= l; i--) {
		if(dp[(t+1)%2][i] + (sum[m]-sum[i]) * (sum[n]-sum[m]) > dp[t%2][m]) {
			dp[t%2][m] = dp[(t+1)%2][i] + (sum[m]-sum[i]) * (sum[n]-sum[m]);
			idx = pre[t][m] = i;
		}
	}
	if(s == e) return;
	dnc(t, s, m, l, idx);
	dnc(t, m+1, e, idx, r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		ll u; cin >> u;
		sum[i] = sum[i-1] + u;
	}
	for(int i = 1; i < n; i++) {
		dp[1][i] = sum[i] * (sum[n] - sum[i]);
	}
	for(int i = 2; i <= k; i++) {
		dnc(i, i, n-1, i-1, n-2);
	}
	
	ll ans = 0;
	int cur;
	for(int i = 1; i < n; i++) {
		if(ans <= dp[k%2][i]) {
			ans = dp[k%2][i];
			cur = i;
		}
	}
	cout << ans << endl;
	if(ans == 0) {
		for(int i = 1; i <= k; i++) {
			cout << i << ' ';
		}
		return 0;
	}
	vector <int> v;
	for(int i = k; i >= 1; i--) {
		cout << cur << ' ';
		cur = pre[i][cur];
	}
}