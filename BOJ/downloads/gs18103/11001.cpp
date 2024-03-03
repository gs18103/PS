#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t[101010], v[101010], ans = 0;
int d;

void f(int s, int e, int l, int r) {
	int m = s + e >> 1, idx;
	ll tans = 0;
	for(int i = max(l, m - d); i <= min(r, m); i++) {
		if(tans < (m - i) * t[m] + v[i]) {
			idx = i;
			tans = (m - i) * t[m] + v[i];
		}
	}
	ans = max(ans, tans);
	if(s == e) return;
	f(s, m, l, idx);
	f(m+1, e, idx, r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	f(1, n, 1, n);
	cout << ans;
}