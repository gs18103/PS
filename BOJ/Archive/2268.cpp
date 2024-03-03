#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll tree[4040404];

ll update(int node, int s, int e, int k, ll val) {
	if(s == e) return tree[node] = val;
	int m = s + e >> 1;
	if(k <= m) return tree[node] = tree[node*2+1] + update(node*2, s, m, k, val);
	else return tree[node] = tree[node*2] + update(node*2+1, m+1, e, k, val);
}

ll cal(int node, int s, int e, int l, int r) {
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
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) update(1, 1, n, b, (ll)c);
		else cout << cal(1, 1, n, min(b, c), max(b, c)) << '\n';
	}
}