#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = INT_MAX >> 1;
const ll LINF = LLONG_MAX >> 1;
const ll mod = 1e9+9;

pll arr[MAX];
int p[MAX], c[MAX], h[MAX], n;

int findSample(){
	for(int i = 0; i < n; i++) {
		arr[i].fi = c[i];
	}
	for(int i = n - 1; i > 0; i--) {
		if(p[i] == 2) {
			arr[h[i]].fi = max(arr[h[i]].fi + arr[i].se, arr[h[i]].se + arr[i].fi);
			arr[h[i]].se = arr[h[i]].se + arr[i].se;
		}
		if(p[i] == 1) {
			arr[h[i]].fi = max({
				arr[h[i]].fi + arr[i].se, 
				arr[h[i]].se + arr[i].fi,
				arr[h[i]].fi + arr[i].fi
			});
			arr[h[i]].se = arr[h[i]].se + arr[i].se;
		}
		if(p[i] == 0) {
			arr[h[i]].fi += arr[i].se;
			arr[h[i]].se += max(arr[i].se, arr[i].fi);
		}
	}
	return max(arr[0].fi, arr[0].se);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for(int i = 1; i < n; i++) {
		cin >> h[i] >> p[i];
	}
	cout << findSample();
	return 0;
}
