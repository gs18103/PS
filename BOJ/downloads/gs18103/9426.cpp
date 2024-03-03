#include <bits/stdc++.h>
#define eb emplace_back

using namespace std;
typedef long long ll;

struct node {
	int l, r, val;
	node(int l, int r, int val) : l(l), r(r), val(val) {} ;
};

int root[303030];
vector <node> tree;

void expand_tree(int s, int e, int k, int pnd, int cnd) {
	if(s == e) {
		tree[cnd].val = tree[pnd].val + 1;
		return;
	}
	int m = s + e >> 1;
	if(k <= m) {
		tree[cnd].r = tree[pnd].r;
		tree[cnd].l = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(s, m, k, tree[pnd].l, tree[cnd].l);
	}
	else {
		tree[cnd].l = tree[pnd].l;
		tree[cnd].r = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(m+1, e, k, tree[pnd].r, tree[cnd].r);
	}
	tree[cnd].val = tree[tree[cnd].l].val + tree[tree[cnd].r].val;
}

int get_kth(int s, int e, int k, int pnd, int cnd) {
	if(s == e) return s;
	int cnt = tree[tree[cnd].l].val - tree[tree[pnd].l].val, m = s + e >> 1;
	if(k <= cnt) return get_kth(s, m, k, tree[pnd].l, tree[cnd].l);
	else return get_kth(m+1, e, k-cnt, tree[pnd].r, tree[cnd].r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, k;
	cin >> n >> k;
	tree.eb(0, 0, 0);
	for(int i = 1, u; i <= n; i++) {
		cin >> u;
		root[i] = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(0, 65535, u, root[i-1], root[i]);
	}

	ll ans = 0;
	for(int i = k; i <= n; i++) {
		ans += (ll)get_kth(0, 65535, (k + 1) / 2, root[i-k], root[i]);
	}
	cout << ans;
}