#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define fi first
#define se second

using namespace std;

struct node {
	int l, r, val;
	node(int l, int r, int val) : l(l), r(r), val(val) {};
};

vector <node> tree;
vector <int> num;
int arr[101010], root[101010];

void expand_tree(int s, int e, int k, int pnd, int cnd) {
	if(s == e) {
		tree[cnd].val = tree[pnd].val + 1;
		return;
	}
	int m = (s + e) / 2;
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

int cal(int s, int e, int node, int l, int r) {
	if(s > r || e < l) return 0;
	if(s >= l && e <= r) return tree[node].val;
	int m = (s + e) / 2;
	return cal(s, m, tree[node].l, l, r) + cal(m+1, e, tree[node].r, l, r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		num.eb(arr[i]);
	}
	sort(all(num));
	tree.eb(0, 0, 0);
	for(int i = 1; i <= n; i++) {
		arr[i] = lower_bound(all(num), arr[i]) - num.begin();
		root[i] = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(0, n-1, arr[i], root[i-1], root[i]);
	}

	cin >> q;
	while(q--) {
		int i, j, k;
		cin >> i >> j >> k;
		k = upper_bound(all(num), k) - num.begin();
		if(k == n) {
			cout << "0\n";
		}
		else cout << cal(0, n-1, root[j], k, n-1) - cal(0, n-1, root[i-1], k, n-1) << "\n";
	}
}