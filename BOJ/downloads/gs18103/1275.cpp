#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll tree[606060];

ll update(int node, int s, int e, int k, ll val) {
	if(s == e) return tree[node] = val;
	int m = s + e >> 1;
	if(k <= m) tree[node] = tree[node*2+1] + update(node*2, s, m, k, val);
	else tree[node] = tree[node*2] + update(node*2+1, m+1, e, k, val);
	return tree[node];
}

ll cal(int node, int s, int e, int l, int r) {
	if(s > r || e < l) return 0LL;
	if(s >= l && e <= r) return tree[node];
	int m = s + e >> 1;
	return cal(node*2, s, m, l, r) + cal(node*2+1, m+1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		ll u;
		cin >> u;
		update(1, 1, n, i, u);
	}

	while(q--) {
		int x, y, a;
		ll b;
		cin >> x >> y >> a >> b;
		if(x > y) swap(x, y);
		cout << cal(1, 1, n, x, y) << '\n';
		update(1, 1, n, a, b);
	}
}