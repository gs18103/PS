#include <bits/stdc++.h>
#define fi first
#define se second
#define mod 1000000007

using namespace std;
typedef pair <int, int> pii;

pii arr[1010101];
pii tree[4040404];
pii dp[1010101];

void update(int node, int s, int e, int k, pii val) {
	if(s == e) {
		tree[node].fi = val.fi;
		tree[node].se = val.se;
		return;
	}
	int m = s + e >> 1;
	if(k <= m) update(node*2, s, m, k, val);
	else update(node*2+1, m+1, e, k, val);
	tree[node].fi = max(tree[node*2].fi, tree[node*2+1].fi);
	tree[node].se = 0;
	if(tree[node].fi == tree[node*2].fi) tree[node].se += tree[node*2].se;
	if(tree[node].fi == tree[node*2+1].fi) tree[node].se += tree[node*2+1].se;
	tree[node].se %= mod;
}

pii cal(int node, int s, int e, int l, int r) {
	if(s > r || e < l) return {0, 0};
	if(s >= l && e <= r) return tree[node];
	int m = s + e >> 1;
	pii c1 = cal(node*2, s, m, l, r), c2 = cal(node*2+1, m+1, e, l, r);
	pii ret = {0, 0};
	ret.fi = max(c1.fi, c2.fi);
	if(ret.fi == c1.fi) ret.se += c1.se;
	if(ret.fi == c2.fi) ret.se += c2.se;
	ret.se %= mod;
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i].fi;
		arr[i].se = i;
	}
	sort(arr+1, arr+n+1);

	queue <int> q;
	for(int i = 1; i <= n; i++) {
		pii tans = cal(1, 1, n, 1, arr[i].se);
		dp[arr[i].se].fi = tans.fi + 1;
		dp[arr[i].se].se = max(1, tans.se);
		q.push(arr[i].se);
		if(i == n || arr[i+1].fi != arr[i].fi) {
			while(!q.empty()){
				int x = q.front();
				q.pop();
				update(1, 1, n, x, dp[x]);
			}
		}
	}
	cout << tree[1].fi << ' ' << tree[1].se << endl;
}