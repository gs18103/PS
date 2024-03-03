#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll tree[5050505];

ll update(int node, int s, int e, int k, ll val) {
	if(s == e) return tree[node] += val;
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

	int q;
	cin >> q;
	while(q--) {
		int a, b, c;
		cin >> a;
		if(a == 1) {
			cin >> b;
			int lb = 1, ub = 1000000;
			while(lb < ub) {
				int m = lb + ub >> 1;
				if(cal(1, 1, 1000000, 1, m) < b) lb = m + 1;
				else ub = m;
			}
			cout << lb << '\n';
			update(1, 1, 1000000, lb, -1);
		}
		else {
			cin >> b >> c;
			update(1, 1, 1000000, b, c);
		}
	}
}