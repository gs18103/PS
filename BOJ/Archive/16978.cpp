#include <bits/stdc++.h>
#define eb emplace_back

using namespace std;
typedef long long ll;

struct node {
	int l, r;
	ll val;
	node(int l, int r, int val) : l(l), r(r), val(val) {};
};

vector <node> tree;
ll arr[101010];
int root[101010];

void init(int s, int e, int cnd) {
	if(s == e) {
		tree[cnd].val = arr[s];
		return;
	}
	int m = s + e >> 1;
	tree[cnd].l = tree.size();
	tree.eb(0, 0, 0);
	init(s, m, tree[cnd].l);
	tree[cnd].r = tree.size();
	tree.eb(0, 0, 0);
	init(m+1, e, tree[cnd].r);
	tree[cnd].val = tree[tree[cnd].l].val + tree[tree[cnd].r].val;
}

void expand_tree(int s, int e, int k, int v, int pnd, int cnd) {
	if(s == e) {
		tree[cnd].val = v;
		return;
	}
	int m = s + e >> 1;
	if(k <= m) {
		tree[cnd].r = tree[pnd].r;
		tree[cnd].l = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(s, m, k, v, tree[pnd].l, tree[cnd].l);
	}
	else {
		tree[cnd].l = tree[pnd].l;
		tree[cnd].r = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(m+1, e, k, v, tree[pnd].r, tree[cnd].r);
	}
	tree[cnd].val = tree[tree[cnd].l].val + tree[tree[cnd].r].val;
}

ll cal(int s, int e, int l, int r, int cnd) {
	if(s > r || e < l) return 0;
	if(s >= l && e <= r) return tree[cnd].val;
	int m = s + e >> 1;
	return cal(s, m, l, r, tree[cnd].l) + cal(m+1, e, l, r, tree[cnd].r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	tree.eb(0, 0, 0);
	init(1, n, 0);

	int q, cnt = 1;
	cin >> q;
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int i, v;
			cin >> i >> v;
			root[cnt] = tree.size();
			tree.eb(0, 0, 0);
			expand_tree(1, n, i, v, root[cnt-1], root[cnt]);
			cnt++;
		}
		if(t == 2) {
			int k, i, j;
			cin >> k >> i >> j;
			cout << cal(1, n, i, j, root[k]) << '\n';
		}
	}
}