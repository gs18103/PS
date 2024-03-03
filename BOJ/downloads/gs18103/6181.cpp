#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()

using namespace std;
typedef pair <int, int> pii;

int n, d;
pii arr[101010];
vector <int> g[101010];
vector <pii> sn, dn;
set <pii> s;

int dis(pii a, pii b) {
	return abs(a.fi-b.fi) + abs(a.se-b.se);
}

bool chk[101010];
int dfs(int x) {
	chk[x] = true;
	int ret = 1;
	for(auto i : g[x]) {
		if(!chk[i]) ret += dfs(i);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i].fi >> arr[i].se;
		sn.eb(arr[i].fi+arr[i].se, i);
		dn.eb(arr[i].fi-arr[i].se, i);
	}
	sort(all(sn));
	sort(all(dn));

	int idx = 0;
	for(int i = 0; i < n; i++) {
		while(idx < n && sn[idx].fi-sn[i].fi <= d) {
			s.insert({arr[sn[idx].se].se-arr[sn[idx].se].fi, sn[idx].se});
			idx++;
		}
		s.erase({arr[sn[i].se].se-arr[sn[i].se].fi, sn[i].se});
		auto it = s.lower_bound({arr[sn[i].se].se-arr[sn[i].se].fi, 0});
		if(it != s.end() && dis(arr[it->se], arr[sn[i].se]) <= d) {
			g[it->se].eb(sn[i].se);
			g[sn[i].se].eb(it->se);
		}
		if(it == s.begin()) continue;
		it--;
		if(dis(arr[it->se], arr[sn[i].se]) <= d) {
			g[it->se].eb(sn[i].se);
			g[sn[i].se].eb(it->se);
		}
	}

	s.clear();
	idx = 0;
	for(int i = 0; i < n; i++) {
		while(idx < n && dn[idx].fi-dn[i].fi <= d) {
			s.insert({arr[dn[idx].se].se+arr[dn[idx].se].fi, dn[idx].se});
			idx++;
		}
		s.erase({arr[dn[i].se].se+arr[dn[i].se].fi, dn[i].se});
		auto it = s.lower_bound({arr[dn[i].se].se+arr[dn[i].se].fi, 0});
		if(it != s.end() && dis(arr[it->se], arr[dn[i].se]) <= d) {
			g[it->se].eb(dn[i].se);
			g[dn[i].se].eb(it->se);
		}
		if(it == s.begin()) continue;
		it--;
		if(dis(arr[it->se], arr[dn[i].se]) <= d) {
			g[it->se].eb(dn[i].se);
			g[dn[i].se].eb(it->se);
		}
	}

	int cnt = 0, mx = 0;
	for(int i = 1; i <= n; i++) {
		if(!chk[i]) {
			cnt++;
			mx = max(mx, dfs(i));
		}
	}
	cout << cnt << ' ' << mx;
}