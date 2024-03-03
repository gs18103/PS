#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

int tree[404040];

int update(int node, int s, int e, int k, int val) {
	if(s == e) return tree[node] = val;
	int m = s + e >> 1;
	if(k <= m) return tree[node] = min(tree[node*2+1], update(node*2, s, m, k, val));
	else return tree[node] = min(tree[node*2], update(node*2+1, m+1, e, k, val));
}

int cal(int node, int s, int e, int l, int r) {
	if(s > r || e < l) return INF;
	if(s >= l && e <= r) return tree[node];
	int m = s + e >> 1;
	return min(cal(node*2, s, m, l, r), cal(node*2+1, m+1, e, l, r));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	memset(tree, INF, sizeof(tree));
	for(int i = 1, u; i <= n; i++) {
		cin >> u;
		update(1, 1, n, i, u);
	}

	int q;
	cin >> q;
	while(q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) update(1, 1, n, b, c);
		else cout << cal(1, 1, n, b, c) << '\n';
	}
}