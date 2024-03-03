#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

pll arr[101010];
ll dp[101010];
vector <pll> stk;

double cross(int x, int y) {
	return ((double)(stk[y].se-stk[x].se)) / (stk[x].fi-stk[y].fi);
}

void insert(ll x, ll y) {
	stk.eb(x, y);
	int sz = stk.size();
	while(sz > 2 && cross(sz-3, sz-2) > cross(sz-2, sz-1)) {
		stk[sz-2] = stk[sz-1];
		stk.pop_back();
		sz = stk.size();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i].fi;
	}
	for(int i = 0; i < n; i++) {
		cin >> arr[i].se;
	}
	insert(arr[0].se, 0);
	int idx = 0;
	for(int i = 1; i < n; i++) {
		while(idx+1 < stk.size() && cross(idx, idx+1) <= (double)arr[i].fi) idx++;
		dp[i] = arr[i].fi * stk[idx].fi + stk[idx].se;
		insert(arr[i].se, dp[i]);
	}
	cout << dp[n-1];
}