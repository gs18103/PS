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

int arr[101010];
pii tree[404040];

pii max2(pii x, pii y) {
	if(x.fi < y.fi) swap(x, y);
	if(x.se > y.fi) return x;
	else return {x.fi, y.fi};
}

void update(int node, int s, int e, int k, int val) {
	if(s == e) {
		tree[node] = {val, 0};
		return;
	}
	int m = s + e >> 1;
	if(k <= m) update(node*2, s, m, k, val);
	else update(node*2+1, m+1, e, k, val);
	tree[node] = max2(tree[node*2], tree[node*2+1]);
}

pii cal(int node, int s, int e, int l, int r) {
	if(s > r || e < l) return {0, 0};
	if(s >= l && e <= r) return tree[node];
	int m = s + e >> 1;
	return max2(cal(node*2, s, m, l, r), cal(node*2+1, m+1, e, l, r));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1, u; i <= n; i++) {
		cin >> u;
		update(1, 1, n, i, u);
	}

	int q;
	cin >> q;
	while(q--) {
		int t, i, j;
		cin >> t >> i >> j;
		if(t == 1) update(1, 1, n, i, j);
		else {
			pii ans = cal(1, 1, n, i, j);
			cout << ans.fi + ans.se << '\n';
		}
	}
}