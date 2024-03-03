#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
int pj[2020], pi[2020];
int dp[2020][2020], cnt[2020][2020];
bool chk[2020][2020];
vector <int> ci[2020], cj[2020], ordj, ordi;
 
void dfsi(int x) {
	if(x)ordi.emplace_back(x);
	for(auto i : ci[x]) {
		dfsi(i);
	}
	return;
}
void dfsj(int x) {
	if(x)ordj.emplace_back(x);
	for(auto i : cj[x]) {
		dfsj(i);
	}
	return;
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1, u, v; i <= n; i++) {
		cin >> u >> v;
		pj[i] = u;
		pi[i] = v;
		cj[u].emplace_back(i);
		ci[v].emplace_back(i);
	}
	for(int i = 1; i <= m; i++) {
		int r, s;
		cin >> r >> s;
		cnt[s][r]++;
	}
	dfsi(0);
	dfsj(0);
 
	for(int i : ordi) {
		for(int j : ordj) {
			dp[i][j] = dp[pi[i]][j] + dp[i][pj[j]] - dp[pi[i]][pj[j]] + cnt[i][j];
		}
	}
 
	for(int i = 1; i <= n; i++) {
		cout << dp[i][i] << '\n';
	}
 
	return 0;
}