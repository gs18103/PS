#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long ll;

ll tree[5050505];

ll update(int node, int s, int e, int k, ll val) {
	if(s == e) return tree[node] = val;
	int m = s + e >> 1;
	if(k <= m) tree[node] = (tree[node*2+1] * update(node*2, s, m, k, val)) % mod;
	else tree[node] = (tree[node*2] * update(node*2+1, m+1, e, k, val)) % mod;
	return tree[node];
}

ll cal(int node, int s, int e, int l, int r) {
	if(s > r || e < l) return 1LL;
	if(s >= l && e <= r) return tree[node];
	int m = s + e >> 1;
	return (cal(node*2, s, m, l, r) * cal(node*2+1, m+1, e, l, r)) % mod;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m, k, q;
	cin >> n >> m >> k;
	q = m + k;
	for(int i = 1; i <= n; i++) {
		ll u;
		cin >> u;
		update(1, 1, n, i, u);
	}

	while(q--) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if(a == 1) update(1, 1, n, b, c);
		else cout << cal(1, 1, n, b, c) << '\n';
	}
}