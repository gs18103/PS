#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef pair <int, int> pii;

pii arr[101010];
int val[101010], c[101010];
vector <int> g[101010];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int u, v; cin >> u >> v;
		arr[i] = {v+u, v-u};
	}
	sort(arr+1, arr+n+1);

	int s = n;
	val[n] = arr[1].se;
	c[1] = 1;
	for(int i = 2; i <= n; i++) {
		int k = upper_bound(val+s, val+n+1, arr[i].se) - val;
		if(k == s) s--;
		val[k-1] = arr[i].se;
		c[i] = n-k+2;
	}
	cout << n - s+1 << '\n';
	for(int i = 1; i <= n; i++) {
		cout << (arr[i].fi-arr[i].se)/2 << ' ' << (arr[i].se+arr[i].fi)/2 << ' ' << c[i] << '\n';
	}
}