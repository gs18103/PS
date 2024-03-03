#include <bits/stdc++.h>
#define eb emplace_back

using namespace std;
typedef long long ll;

int tree[101010], arr[303030];

void update(int i, int val) {
	while(i <= 100000) {
		tree[i] += val;
		i += (i & -i);
	}
}

int cal(int i) {
	int ret = 0;
	while(i) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, k;
	cin >> n >> k;
	for(int i = 1, u; i <= n; i++) {
		cin >> arr[i];
		arr[i]++;
	}

	for(int i = 1; i < k; i++) {
		update(arr[i], 1);
	}
	ll ans = 0;
	for(int i = k; i <= n; i++) {
		update(arr[i], 1);
		if(i-k) update(arr[i-k], -1);
		int lb = 1, ub = 100000;
		while(lb < ub) {
			int m = lb + ub >> 1;
			if(cal(m) >= (k+1)/2) ub = m;
			else lb = m + 1;
		}
		ans += (ll)(lb - 1);
	}
	cout << ans;
}