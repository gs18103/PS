#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()

using namespace std;

struct node {
	int l, r, val;
	node(int l, int r, int val) : l(l), r(r), val(val) {};
};

int arr[101010], root[101010], p[20][101010], dep[101010];
vector <node> tree;
vector <int> num, g[101010];

void expand_tree(int s, int e, int k, int diff, int pnd, int cnd) {
	if(s == e) {
		tree[cnd].val = tree[pnd].val + diff;
		return;
	}
	int m = (s + e) / 2;
	if(k <= m) {
		tree[cnd].r = tree[pnd].r;
		tree[cnd].l = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(s, m, k, diff, tree[pnd].l, tree[cnd].l);
	}
	else {
		tree[cnd].l = tree[pnd].l;
		tree[cnd].r = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(m+1, e, k, diff, tree[pnd].r, tree[cnd].r);
	}
	tree[cnd].val = tree[tree[cnd].l].val + tree[tree[cnd].r].val;
}

int get_ans(int s, int e, int l, int r, int b1, int b2, int k) {
	if(s == e) return s;
	int m = (s + e) / 2;
	int cnt = tree[tree[r].l].val + tree[tree[l].l].val - tree[tree[b1].l].val - tree[tree[b2].l].val;
	if(cnt < k) return get_ans(m+1, e, tree[l].r, tree[r].r, tree[b1].r, tree[b2].r, k - cnt);
	else return get_ans(s, m, tree[l].l, tree[r].l, tree[b1].l, tree[b2].l, k);
}

void dfs(int x, int pa, int dd, int n) {
	p[0][x] = pa;
	dep[x] = dd;
	root[x] = tree.size();
	tree.eb(0, 0, 0);
	arr[x] = lower_bound(all(num), arr[x]) - num.begin();
	expand_tree(0, n-1, arr[x], 1, root[pa], root[x]);
	for(auto i : g[x]) {
		if(i == pa) continue;
		dfs(i, x, dd+1, n);
	}
}

int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 19; i >= 0; i--) {
		if((1<<i) <= dep[u] - dep[v]) {
			u = p[i][u];
		}
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; i--) {
		if(p[i][u] != 0 && p[i][u] != p[i][v]) {
			u = p[i][u];
			v = p[i][v];
		}
	}
	return p[0][u];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		num.eb(arr[i]);
	}
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].eb(v), g[v].eb(u);
	}
	sort(all(num));
	tree.eb(0, 0, 0);
	dfs(1, 0, 0, n);

	for(int i = 1; i < 20; i++) {
		for(int j = 1; j <= n; j++) {
			p[i][j] = p[i-1][p[i-1][j]];
		}
	}
	while(q--) {
		int i, j, k;
		cin >> i >> j >> k;
		cout << num[get_ans(0, n-1, root[i], root[j], root[lca(i, j)], root[p[0][lca(i, j)]], k)] << '\n';
	}
}