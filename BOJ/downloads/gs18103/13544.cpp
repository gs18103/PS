#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define INF 2e9
#define LINF 1e18
#define g(tp, x) get<x>(tp)

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

struct node {
	int l, r, val;
	node(int L, int R, int Val) : l(L), r(R), val(Val) {};
};

vector <node> tree;
vector <int> num;
int arr[101010], root[101010];

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

int get_ans(int s, int e, int pnd, int cnd, int k) {
	if(e < k) return 0;
	if(s >= k) return tree[cnd].val - tree[pnd].val;
	int m = s + e >> 1;
	return get_ans(s, m, tree[pnd].l, tree[cnd].l, k) + get_ans(m+1, e, tree[pnd].r, tree[cnd].r, k);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		num.eb(arr[i]);
	}

	sort(all(num));
	tree.eb(0, 0, 0);
	for(int i = 1; i <= n; i++) {
		arr[i] = lower_bound(all(num), arr[i])-num.begin();
		root[i] = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(0, n-1, arr[i], root[i-1], root[i]);
	}

	int q, la = 0;
	cin >> q;
	while(q--) {
		int i, j, k;
		cin >> i >> j >> k;
		i ^= la, j ^= la, k ^= la;
		la = get_ans(0, n-1, root[i-1], root[j], upper_bound(all(num), k)-num.begin());
		cout << la << '\n';
	}
}