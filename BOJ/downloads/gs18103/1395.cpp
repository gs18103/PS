#include <bits/stdc++.h>

using namespace std;

int tree[404040], lazy[404040];

void update_lazy(int node, int s, int e) {
	if(lazy[node]) {
		tree[node] = e - s + 1 - tree[node];
		if(s != e) {
			lazy[node*2] ^= 1;
			lazy[node*2+1] ^= 1;
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int s, int e, int l, int r) {
	update_lazy(node, s, e);
	if(s > r || e < l) return;
	if(s >= l && e <= r) {
		tree[node] = e - s + 1-tree[node];
		if(s != e) {
			lazy[node*2] ^= 1;
			lazy[node*2+1] ^= 1;
		}
		return;
	}
	int m = s + e >> 1;
	update_range(node*2, s, m, l, r);
	update_range(node*2+1, m+1, e, l, r);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int cal(int node, int s, int e, int l, int r) {
	update_lazy(node, s, e);
	if(s > r || e < l) return 0;
	if(s >= l && e <= r) return tree[node];
	int m = s + e >> 1;
	return cal(node*2, s, m, l, r) + cal(node*2+1, m+1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q;
	cin >> n >> q;
	while(q--) {
		int t, i, j;
		cin >> t >> i >> j;
		if(t == 0) update_range(1, 1, n, i, j);
		else cout << cal(1, 1, n, i, j) << '\n';
	}
}