#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;

int n;
int a[10010];
int cnt[10010];
ll ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for(int i=1; i<=n; i++) {
		ans += min(a[i], cnt[i]) * 2;
		a[i] -= min(a[i], cnt[i]);

		ll l = min(a[i], a[i+1]);
		a[i] -= l;
		a[i+1] -= l;
		cnt[i+2] = l;
		
		ans += l * 5;

		ans += a[i] * 3;
		
	}

	cout << ans << "\n";

	return 0;
}
