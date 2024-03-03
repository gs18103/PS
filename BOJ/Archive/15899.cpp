#include <bits/stdc++.h>
#define mod 1000000007
#define eb emplace_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int in[202020], out[202020], tree[808080];
pii query[202020], c[202020];
vector <int> g[202020];

int cnt = 0;
int dfs(int x, int pa) {
	in[x] = out[x] = ++cnt;
	for(auto i : g[x]) {
		if(i == pa) continue;
		out[x] = max(out[x], dfs(i, x));
	}
	return out[x];
}

int update(int node, int s, int e, int k, int val) {
	if(s == e) return tree[node] += val;
	int m = s + e >> 1;
	if(k <= m) return tree[node] = tree[node*2+1] + update(node*2, s, m, k, val);
	else return tree[node] = tree[node*2] + update(node*2+1, m+1, e, k, val);
}

int cal(int node, int s, int e, int l, int r) {
	if(s > r || e < l) return 0;
	if(s >= l && e <= r) return tree[node];
	int m = s + e >> 1;
	return cal(node*2, s, m, l, r) + cal(node*2+1, m+1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q, C;
	cin >> n >> q >> C;
	for(int i = 1; i <= n; i++) {
		cin >> c[i].fi;
		c[i].se = i;
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].eb(v);
		g[v].eb(u);
	}
	for(int i = 1; i <= q; i++) {
		cin >> query[i].se >> query[i].fi;
	}

	sort(query+1, query+q+1);
	sort(c+1, c+n+1);
	dfs(1, 0);

	int idx = 1;
	ll ans = 0;
	for(int i = 1; i <= q; i++) {
		while(idx <= n && c[idx].fi <= query[i].fi) {
			update(1, 1, n, in[c[idx].se], 1);
			idx++;
		}
		ans += cal(1, 1, n, in[query[i].se], out[query[i].se]);
	}
	cout << ans % mod;
}