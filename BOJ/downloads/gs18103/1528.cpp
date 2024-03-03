#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

int dp[1010101];
int pre[1010101];
vector <int> val;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= 6; i++) {
		for(int j = 0; j < (1 << i); j++) {
			int temp = 0;
			for(int k = 0; k < i; k++) {
				if(j & (1 << k)) temp = temp * 10 + 4;
				else temp = temp * 10 + 7;
			}
			val.push_back(temp);
		}
	}
	sort(val.begin(), val.end());
	reverse(val.begin(), val.end());

	for(int i = 1; i <= n; i++) {
		dp[i] = INF;
	}

	for(auto i : val) {
		for(int j = 0; j <= n - i; j++) {
			if(dp[j+i] >= dp[j] + 1) {
				dp[j+i] = dp[j] + 1;
				pre[j+i] = i;
			}
		}
	}
	if(dp[n] == INF) {
		cout << -1;
		return 0;
	}
	while(n) {
		cout << pre[n] << ' ';
		n -= pre[n];
	}
}