#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

bool chk[101010];
vector <ll> p;

int dn(ll x) {
	int ans = 0;
	for(auto i : p) {
		if(i * i > x) break;
		if(x % i == 0) {
			x /= i;
			if(x % i == 0) return -1;
			ans++;
		}
	}
	if(x != 1) ans++;
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int k;
	cin >> k;
	for(int i = 2; i <= 1000; i++) {
		if(chk[i]) continue;
		for(int j = i * i; j <= 100000; j += i) {
			chk[j] = true;
		}
	}
	for(int i = 2; i <= 100000; i++) {
		if(!chk[i]) p.push_back(i);
	}

	ll lb = 1, ub = 2000000000;
	while(lb < ub) {
		ll m = lb + ub >> 1, cnt = 0;
		for(ll i = 2; i * i <= m; i++) {
			int flag = dn(i);
			if(flag % 2 == 1) cnt += m / (i * i);
			else if(flag != -1) cnt -= m / (i * i);
		}
		if(m - cnt >= k) ub = m;
		else lb = m + 1;
	}
	cout << lb;
}