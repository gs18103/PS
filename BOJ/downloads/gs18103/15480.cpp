#include <bits/stdc++.h>
#define eb emplace_back

using namespace std;

vector <int> g[101010];

int p[20][101010], dep[101010];

void dfs(int x, int pa, int d) {
	dep[x] = d;
	for(auto i : g[x]) {
		if(i == pa) continue;
		dfs(i, x, d+1);
		p[0][i] = x;
	}
}

int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 19; i >= 0; i--) {
		if((1<<i) <= dep[u] - dep[v]) u = p[i][u];
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; i--) {
		if(p[i][u] != p[i][v]) u = p[i][u], v = p[i][v];
	}
	return p[0][u];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].eb(v), g[v].eb(u);
	}
	dfs(1, 0, 0);

	for(int i = 1; i < 20; i++) {
		for(int j = 1; j <= n; j++) {
			p[i][j] = p[i-1][p[i-1][j]];
		}
	}

	int q;
	cin >> q;
	while(q--) {
		int r, u, v; cin >> r >> u >> v;
		int l1 = lca(r, u), l2 = lca(u, v), l3 = lca(v, r);
		int md = max(dep[l1], max(dep[l2], dep[l3]));
		if(dep[l1] == md) cout << l1 << '\n';
		else if(dep[l2] == md) cout << l2 << '\n';
		else cout << l3 << '\n';
	}
}