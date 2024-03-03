#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define g(tp, x) get<x>(tp)

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef tuple <int, int, int> tp3;

int deg[1010], p[1010];
vector <int> g[1010];
vector <pii> tE;
vector <tp3> E;

int find(int x) {
	return p[x] == 0 ? x : p[x] = find(p[x]);
}

void uni(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	p[max(x, y)] = min(x, y);
}

ll dfs(int x, int pa) {
	ll ret = 0;
	for(auto i : g[x]) {
		if(i == pa) continue;
		ret += dfs(i, x);
		ret += deg[x];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m, rt;
	cin >> n >> m >> rt;
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		deg[u]++, deg[v]++;
		tE.eb(u, v);
	}
	for(auto i : tE) {
		int w = deg[i.fi] + deg[i.se];
		E.eb(w, i.fi, i.se);
	}
	sort(all(E));
	for(auto i : E) {
		int u = g(i, 1), v = g(i, 2), w = g(i, 0);
		if(find(u) == find(v)) continue;
		g[u].eb(v);
		g[v].eb(u);
		uni(u, v);
	}
	cout << dfs(rt, 0);
}