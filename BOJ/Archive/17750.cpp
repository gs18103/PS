#include <bits/stdc++.h>
#define LINF 1000000000000000000LL
 
using namespace std;
typedef long long ll;
 
ll t[101010];
ll tree[804040], b[101010], dp[101010];
vector <ll> num;
 
ll update(ll node, ll s, ll e, ll k, ll val) {
	if(s == e) return tree[node] = max(tree[node], val);
	ll m = (s+e)>>1;
	if(k <= m) tree[node] = max(tree[node*2+1], update(node*2, s, m, k, val));
	else tree[node] = max(tree[node*2], update(node*2+1, m+1, e, k, val));
	return tree[node];
}
 
ll cal(ll node, ll s, ll e, ll l, ll r) {
	if(s > r || e < l) return -LINF;
	if(s >= l && e <= r) return tree[node];
	ll m = (s+e)>>1;
	return max(cal(node*2, s, m, l, r), cal(node*2+1, m+1, e, l, r));
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
 
	ll K, M, D, n;
	ll A;
	cin >> K >> M >> D >> A >> n;
	M -= K;
	for(ll i = 1; i <= n; i++) {
		cin >> t[i] >> b[i];
		t[i] -= K;
		num.push_back(t[i] % D);
	}
	num.push_back(M % D);
	num.push_back(0);
	t[n+1] = M;
	sort(num.begin(), num.end());
	for(ll i = 0; i < 804040; i++) tree[i] = -LINF;
	update(1, 0, num.size()-1, 0, 0LL);
	for(ll i = 1; i <= n+1; i++) {
		ll k = lower_bound(num.begin(), num.end(), t[i] % D) - num.begin();
		dp[i] = max(cal(1, 0, num.size()-1, 0, k-1) - A, cal(1, 0, num.size()-1, k, num.size()-1)) + b[i];
		update(1, 0, num.size()-1, k, dp[i]);
	}
	cout << dp[n+1] - A * (M / D);
}
