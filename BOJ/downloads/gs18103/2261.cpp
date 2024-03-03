#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

vector <pll> arr;

ll dist(pll p1, pll p2) {
	return (p1.fi-p2.fi)*(p1.fi-p2.fi) + (p1.se-p2.se)*(p1.se-p2.se);
}

ll dnc(int s, int e) {
	if(s == e) return 1LL << 60;
	int m = (s + e) >> 1;
	ll mix = (arr[m].fi + arr[m+1].fi) / 2;
	ll ret = min(dnc(s, m), dnc(m+1, e));
	int d1 = s, d2 = m+1;
	vector <pll> tarr, mip;
	while(d1 <= m & d2 <= e) {
		if(arr[d1].se > arr[d2].se) tarr.eb(arr[d1++]);
		else tarr.eb(arr[d2++]);
	}
	while(d1 <= m) tarr.eb(arr[d1++]);
	while(d2 <= e) tarr.eb(arr[d2++]);
	for(int i = 0; i < tarr.size(); i++) {
		arr[s+i] = tarr[i];
		if((tarr[i].fi - mix) * (tarr[i].fi - mix) <= ret) mip.eb(tarr[i]);
	}
	for(int i = 0; i < mip.size(); i++) {
		for(int j = i + 1; j <= min(i + 10, (int)mip.size()-1); j++) {
			ret = min(ret, dist(mip[i], mip[j]));
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	arr.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i].fi >> arr[i].se;
	}
	sort(all(arr));
	arr.erase(unique(all(arr)), arr.end());
	cout << dnc(0, n-1);
}