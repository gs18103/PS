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

pii tree[505050];

pii update(int node, int s, int e, int k, int val) {
	if(s == e) return tree[node] = {val, s};
	int m = s + e >> 1;
	if(k <= m) tree[node] = min(tree[node*2+1], update(node*2, s, m, k, val));
	else tree[node] = min(tree[node*2], update(node*2+1, m+1, e, k, val));
	return tree[node];
}

pii cal(int node, int s, int e, int l, int r) {
	if(s > r || e < l) return {INF, INF};
	if(s >= l && e <= r) return tree[node];
	int m = s + e >> 1;
	return min(cal(node*2, s, m, l, r), cal(node*2+1, m+1, e, l, r));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q;
	cin >> n;
	for(int i = 1, u; i <= n; i++) {
		cin >> u;
		update(1, 1, n, i, u);
	}

	cin >> q;
	while(q--) {
		int t, i, j;
		cin >> t >> i >> j;
		if(t == 1) update(1, 1, n, i, j);
		else cout << cal(1, 1, n, i, j).se << '\n';
	}
}