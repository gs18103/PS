#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
typedef pair <int, int> pii;
typedef long long ll;

vector <int> g[10101], ans;
bool chk[2][10101], cho[10101];
int w[10101], dp[2][10101];

int dfs(int x, int p, int flag) {
	if(chk[flag][x]) return dp[flag][x];
	chk[flag][x] = true;
	int temp = 0;
	if(flag) {
		temp = w[x];
		for(auto i : g[x]) {
			if(i == p) continue;
			temp += dfs(i, x, 0);
		}
	}
	for(auto i : g[x]) {
		if(i == p) continue;
		dp[flag][x] += dfs(i, x, 1);
	}
	if(temp > dp[flag][x]) cho[x] = true;
	return dp[flag][x] = max(dp[flag][x], temp);
}

void find_ans(int x, int p, bool flag) {
	if(cho[x] && flag) {
		ans.eb(x);
		for(auto i : g[x]) {
			if(i == p) continue;
			find_ans(i, x, false);
		}
	}
	else {
		for(auto i : g[x]) {
			if(i == p) continue;
			find_ans(i, x, true);
		}
	}
}

int main() {
	fastio;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].eb(v);
		g[v].eb(u);
	}
	cout << dfs(1, 0, 1) << '\n';
	find_ans(1, 0, true);
	sort(all(ans));
	for(auto i : ans) {
		cout << i << ' ';
	}
}