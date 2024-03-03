#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define fi first
#define se second
#define INF 2000000000
#define LINF 1000000000000000000LL
#define N 101010

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

vector <int> g[N];
int ord[N], low[N], p[N];
bool chk[N];

int cnt = 0;
void dfs(int x, int pre) {
	chk[x] = true;
	p[x] = pre;
	ord[x] = low[x] = ++cnt;
	for(auto i : g[x]) {
		if(i == pre) continue;
		if(chk[i]) {
			low[x] = min(low[x], ord[i]);
		}
		else {
			dfs(i, x);
			low[x] = min(low[x], low[i]);
		}
	}
}

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1, 0);

	vector <pii> ans;
	for(int i = 1; i <= n; i++) {
		sort(all(g[i]));
		for(auto j : g[i]) {
			if(j < i) continue;
			if(low[i] > ord[j] || low[j] > ord[i]) ans.eb(i, j);
		}
	}

	cout << ans.size() << '\n';
	for(auto i : ans) {
		cout << i.fi << ' ' << i.se << '\n';
	}
}