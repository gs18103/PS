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

ll arr[101010];
ll tree[404040];

void update(int node, int s, int e, int l, int r, int val) {
	if(s > r | e < l) return;
	if(s >= l && e <= r) {
		tree[node] += val;
		return;
	}
	int m = s + e >> 1;
	update(node*2, s, m, l, r, val);
	update(node*2+1, m+1, e, l, r, val);
}

ll cal(int node, int s, int e, int k) {
	if(s == e) return tree[node];
	int m = s + e >> 1;
	if(k <= m) return tree[node] + cal(node*2, s, m, k);
	else return tree[node] + cal(node*2+1, m+1, e, k);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int q;
	cin >> q;
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int i, j, k;
			cin >> i >> j >> k;
			update(1, 1, n, i, j, k);
		}
		else {
			int x;
			cin >> x;
			cout << cal(1, 1, n, x) + arr[x] << '\n';
		}
	}
}