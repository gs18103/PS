#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;

int n;
ll b, c;
ll a[1010101];
ll cnt[1010101];
ll ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> b >> c;

	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	if(c >= b) {
		for(int i = 1; i <= n; i++) {
			ans += a[i] * b;
		}
		cout << ans;
		return 0;
	}

	for(int i=1; i<=n; i++) {
		ans += min(a[i], cnt[i]) * c;
		a[i] -= min(a[i], cnt[i]);

		ll l = min(a[i], a[i+1]);
		a[i] -= l;
		a[i+1] -= l;
		cnt[i+2] = l;
		
		ans += l * (b + c);
		ans += a[i] * b;
	}

	cout << ans << "\n";

	return 0;
}
