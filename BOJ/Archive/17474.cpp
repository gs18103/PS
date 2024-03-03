#include <bits/stdc++.h>
#define LINF 1000000000000000000

using namespace std;
typedef long long ll;

struct Node {
	ll mx1, mx2, cnt, sum;
};

Node tree[4040404];
ll arr[1010101];

Node mrg(Node a, Node b){
	if(a.mx1 == b.mx1) return {a.mx1, max(a.mx2, b.mx2), a.cnt + b.cnt, a.sum + b.sum};
	if(a.mx1 > b.mx1) swap(a, b);
	return {b.mx1, max(a.mx1, b.mx2), b.cnt, a.sum + b.sum};
}

void push(int node, int s, int e) {
	if(s == e) return;
	for(int i = node*2; i <= node*2+1; i++) {
		if(tree[node].mx1 < tree[i].mx1) {
			tree[i].sum -= (tree[i].mx1 - tree[node].mx1) * tree[i].cnt;
			tree[i].mx1 = tree[node].mx1;
		}
	}
}

Node init(int node, int s, int e) {
	if(s == e) return tree[node] = {arr[s], -1, 1, arr[s]};
	int m = s + e >> 1;
	return tree[node] = mrg(init(node*2, s, m), init(node*2+1, m+1, e));
}

void update(int node, int s, int e, int l, int r, ll val) {
	push(node, s, e);
	if(s > r || e < l || tree[node].mx1 <= val) return;
	if(s >= l && e <= r && tree[node].mx2 < val) {
		tree[node].sum -= (tree[node].mx1 - val) * tree[node].cnt;
		tree[node].mx1 = val;
		push(node, s, e);
		return;
	}
	int m = s + e >> 1;
	update(node*2, s, m, l, r, val);
	update(node*2+1, m+1, e, l, r, val);
	tree[node] = mrg(tree[node*2], tree[node*2+1]);
}

ll cal_max(int node, int s, int e, int l, int r) {
	push(node, s, e);
	if(s > r || e < l) return 0;
	if(s >= l && e <= r) return tree[node].mx1;
	int m = s + e >> 1;
	return max(cal_max(node*2, s, m, l, r), cal_max(node*2+1, m+1, e, l, r));
}

ll cal_sum(int node, int s, int e, int l, int r) {
	push(node, s, e);
	if(s > r || e < l) return 0;
	if(s >= l && e <= r) return tree[node].sum;
	int m = s + e >> 1;
	return cal_sum(node*2, s, m, l, r) + cal_sum(node*2+1, m+1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);

	int q;
	cin >> q;
	while(q--) {
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 1) {
			ll x;
			cin >> x;
			update(1, 1, n, l, r, x);
		}
		if(t == 2) cout << cal_max(1, 1, n, l, r) << '\n';
		if(t == 3) cout << cal_sum(1, 1, n, l, r) << '\n';
	}
}