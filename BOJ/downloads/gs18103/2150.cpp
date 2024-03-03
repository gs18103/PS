#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef pair <int, int> pii;

int sz, low[505050], num[505050], scc[505050];
stack <int> stk;
vector <int> g[505050];
bool chk[505050];

int cnt;
void dfs(int x) {
	if(num[x]) return;
	low[x] = num[x] = ++cnt;
	stk.push(x);
	for(auto i : g[x]) {
		if(num[i] == 0) {
			dfs(i);
			low[x] = min(low[x], low[i]);
		}
		else if(!chk[i]) {
			low[x] = min(low[x], num[i]);
		}
	}
	if(low[x] == num[x]) {
		sz++;
		while(!stk.empty()) {
			int u = stk.top();
			stk.pop();
			chk[u] = true;
			scc[u] = sz;
			if(x == u) break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g[u].emplace_back(v);
	}

	for(int i = 1; i <= n; i++) {
		if(num[i] == 0)dfs(i);
	}
	vector <vector <int> > ans;
	ans.resize(sz);
	for(int i = 1; i <= n; i++) {
		ans[scc[i]-1].emplace_back(i);
	}
	for(int i = 0; i < sz; i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	sort(ans.begin(), ans.end(), [](vector <int> a, vector <int> b) {
		return a[0] < b[0];
	});

	cout << sz << endl;
	for(int i = 0; i < sz; i++) {
		for(auto j : ans[i]) cout << j << ' ';
		cout << -1 << '\n';
	}
}