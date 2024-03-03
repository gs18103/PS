#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef pair <int, int> pii;

int val[505050], ind[505050], nval[505050];
int sz, low[505050], num[505050], scc[505050];
stack <int> stk;
vector <int> g[505050], ng[505050];
bool chk[505050], res[505050];
int tans[505050];

int cnt;
void dfs(int x) {
	if(chk[x]) return;
	chk[x] = true;
	low[x] = num[x] = ++cnt;
	stk.push(x);
	for(auto i : g[x]) {
		if(num[i] == 0) {
			dfs(i);
			low[x] = min(low[x], low[i]);
		}
		else if(chk[i]) {
			low[x] = min(low[x], num[i]);
		}
	}
	if(low[x] == num[x]) {
		sz++;
		while(!stk.empty()) {
			int u = stk.top();
			stk.pop();
			chk[u] = false;
			scc[u] = sz;
			if(x == u) break;
		}
	}
}

bool nchk[505050];
void ndfs(int x) {
	if(nchk[x]) return;
	nchk[x] = true;
	for(auto i : ng[x]) {
		ind[i]++;
		ndfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m, st, p;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g[u].emplace_back(v);
	}
	for(int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	cin >> st >> p;
	for(int i = 1; i <= p; i++) {
		int u; cin >> u;
		res[u] = true;
	}

	for(int i = 1; i <= n; i++) {
		if(num[i] == 0)dfs(i);
	}

	for(int i = 1; i <= n; i++) {
		nval[scc[i]] += val[i];
		for(auto j : g[i]) {
			if(scc[j] != scc[i]) {
				ng[scc[i]].emplace_back(scc[j]);
			}
		}
	}
	st = scc[st];
	ndfs(st);	
	queue <int> q;
	q.push(st);
	tans[st] = nval[st];
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(auto i : ng[x]) {
			ind[i]--;
			tans[i] = max(tans[i], tans[x] + nval[i]);
			if(ind[i] == 0) q.push(i);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(res[i]) ans = max(ans, tans[scc[i]]);
	}
	cout << ans << endl;
}