#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define eb emplace_back

using namespace std;

struct node {
	int l, r, val;
	node(int l, int r, int val) : l(l), r(r), val(val) {};
};

int arr[303030], root[303030];
vector <int> num;
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
	int m = s + e >> 1;
	int cnt = tree[tree[cnd].l].val - tree[tree[pnd].l].val;
	if(k <= cnt) return get_kth(s, m, k, tree[pnd].l, tree[cnd].l);
	else return get_kth(m+1, e, k - cnt, tree[pnd].r, tree[cnd].r);
}

int cal(int s, int e, int k, int pnd, int cnd) {
	if(s == e) return tree[cnd].val - tree[pnd].val;
	int m = s + e >> 1;
	if(k <= m) return cal(s, m, k, tree[pnd].l, tree[cnd].l);
	else return cal(m+1, e, k, tree[pnd].r, tree[cnd].r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, c;
	cin >> n >> c;
	tree.eb(0, 0, 0);
	for(int i = 1; i <= n; i++) {
		int u; cin >> u;
		root[i] = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(1, c, u, root[i-1], root[i]);
	}
	int q;
	cin >> q;
	while(q--) {
		int l, r, ans = n+1;
		cin >> l >> r;
		int k1 = get_kth(1, c, 1, root[l-1], root[r]);
		int k2 = get_kth(1, c, (r-l+1)/2+1, root[l-1], root[r]);
		if(cal(1, c, k1, root[l-1], root[r]) > (r-l+1)/2) cout << "yes " << k1 << '\n';
		else if(cal(1, c, k2, root[l-1], root[r]) > (r-l+1)/2) cout << "yes " << k2 << '\n';
		else cout << "no\n";
	}
}