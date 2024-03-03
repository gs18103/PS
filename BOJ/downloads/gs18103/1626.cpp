#include <bits/stdc++.h>
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define g(tp, x) get<x>(tp)
#define INF 1e9
#define LINF 1e18
#define N 101010
#define mp make_pair
#define err while(1)
#define test 1

using namespace std;
typedef long long ll;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
typedef tuple <ll, int, int> tp3;

vector <pil> g[N];
vector <tp3> E;
bool chk[4*N];

int p[22][N], dep[N], dsu[N];
pll val[22][N];

int find(int x) {
	return (dsu[x] == 0 ? x : dsu[x] = find(dsu[x]));
}

void uni(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	dsu[max(x, y)] = min(x, y);
}

void upd(pll &ret, pll v) {
	if(ret.fi < v.fi) ret.se = ret.fi, ret.fi = v.fi;
	else if(ret.fi != v.fi && v.fi > ret.se) ret.se = v.fi;
	if(ret.fi < v.se) ret.se = ret.fi, ret.fi = v.se;
	else if(ret.fi != v.se && v.se > ret.se) ret.se = v.se;
}

pll lca(int u, int v) {
	pll ret = {-1, -1};
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 20; i >= 0; i--) {
		if(dep[u] - dep[v] >= (1<<i)) {
			upd(ret, val[i][u]);
			u = p[i][u];
		}
	}
	if(u == v) {
		return ret;
	}
	for(int i = 20; i >= 0; i--) {
		if(p[i][u] != p[i][v] && p[i][u] != 0) {
			upd(ret, val[i][u]), upd(ret, val[i][v]);
			u = p[i][u], v = p[i][v];
		}
	}
	upd(ret, val[0][u]), upd(ret, val[0][v]);
	return ret;
}

int cnt = 0;
void dfs(int x, int pa, int dd) {
	cnt++;
	dep[x] = dd;
	for(auto i : g[x]) {
		if(i.fi == pa) continue;
		dfs(i.fi, x, dd+1);
		p[0][i.fi] = x;
		val[0][i.fi] = mp(i.se, -1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v; ll w;
		if(u == v) continue;
		cin >> u >> v >> w;
		E.eb(w, u, v);
	}

	ll ans = 0;
	sort(all(E));
	for(int i = 0; i < m; i++) {
		int u = g(E[i], 1), v = g(E[i], 2); ll w = g(E[i], 0);
		if(find(u) == find(v)) continue;
		chk[i] = true;
		uni(u, v);
		ans += w;
		g[u].eb(v, w);
		g[v].eb(u, w);
	}

	dfs(1, 0, 0);
	if(cnt != n) {
		cout << -1;
		return 0;
	}
	for(int i = 1; i < 22; i++) {
		for(int j = 1; j <= n; j++) {
			p[i][j] = p[i-1][p[i-1][j]];
			val[i][j] = {-1, -1};
			upd(val[i][j], val[i-1][p[i-1][j]]);
			upd(val[i][j], val[i-1][j]);
		}
	}

	ll add = 1000000000000000000LL;
	for(int i = 0; i < m; i++) {
		if(chk[i]) continue;
		int u = g(E[i], 1), v = g(E[i], 2); ll w = g(E[i], 0);
		pll val = lca(u, v);
		if(w > val.fi) add = min(add, w - val.fi);
		else if(val.se != -1) add = min(add, w - val.se);
	}
	if(add == 1000000000000000000LL) cout << -1;
	else cout << ans + add;
}