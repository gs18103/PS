#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll tree[808080];
ll arr[202020], diff[202020], lazy[202020];

ll gcd(ll x, ll y) {
	if(y == 0) return x;
	return gcd(y, x % y);
}

ll init(int node, int s, int e) {
	if(s == e) return tree[node] = diff[s];
	int m = s + e >> 1;
	return tree[node] = gcd(init(node*2, s, m), init(node*2+1, m+1, e));
}

ll update(int node, int s, int e, int k, ll val) {
	if(s == e) return tree[node] = val;
	int m = s + e >> 1;
	if(k <= m) return tree[node] = gcd(update(node*2, s, m, k, val), tree[node*2+1]);
	else return tree[node] = gcd(update(node*2+1, m+1, e, k, val), tree[node*2]);
}

ll cal(int node, int s, int e, int l, int r) {
	if(s > r || e < l) return 0;
	if(s >= l && e <= r) return tree[node];
	int m = s + e >> 1;
	return gcd(cal(node*2, s, m, l, r), cal(node*2+1, m+1, e, l, r));
}

void update_lazy(int node, int s, int e) {
	if(s == e) return;
	lazy[node*2] += lazy[node];
	lazy[node*2+1] += lazy[node];
	lazy[node] = 0;
}

void update_range(int node, int s, int e, int l, int r, ll val) {
	update_lazy(node, s, e);
	if(s > r || e < l) return;
	if(s >= l && e <= r) {
		lazy[node] += val;
		return;
	}
	int m = s + e >> 1;
	update_range(node*2, s, m, l, r, val);
	update_range(node*2+1, m+1, e, l, r, val);
}

ll get_arr(int node, int s, int e, int k) {
	update_lazy(node, s, e);
	if(k == 0) return 0;
	if(s == e)  {
		return lazy[node] + arr[k];
	}
	int m = s + e >> 1;
	if(k <= m) return get_arr(node*2, s, m, k);
	else return get_arr(node*2+1, m+1, e, k);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		diff[i] = abs(arr[i] - arr[i-1]);
	}
	init(1, 1, n);

	int q;
	cin >> q;
	while(q--) {
		ll t, a, b;
		cin >> t >> a >> b;
		if(t) {
			update_range(1, 1, n, a, b, t);
			update(1, 1, n, a, abs(get_arr(1, 1, n, a) - get_arr(1, 1, n, a-1)));
			if(b < n) update(1, 1, n, b+1, abs(get_arr(1, 1, n, b+1) - get_arr(1, 1, n, b)));
		}
		else {
			ll g = cal(1, 1, n, a+1, b);
			cout << gcd(g, get_arr(1, 1, n, b)) << '\n';
		}
	}
    
    return 0;
}