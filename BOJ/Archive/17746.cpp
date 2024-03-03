#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define fi first
#define se second
#define G(tp, x) get<(x)>(tp)
#define INF 2000000000
#define LINF 1000000000000000000LL
 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef tuple <int, int, int> tp3;
 
vector <pii> g[202020];
vector <tp3> arr, rx, ry;
 
int main() {
	fastio;
	int n, m, c;
	cin >> n >> m >> c;
	for(int i = 0, u, v; i < n; i++) {
		cin >> u >> v;
		arr.eb(u, v, i);
	}
	for(int i = 0, p, q, r, s; i < m; i++) {
		cin >> p >> q >> r >> s;
		rx.eb(p, q, i);
		rx.eb(r+1, q, i);
		ry.eb(q, r, i);
		ry.eb(s+1, r, i);
	}
	sort(all(arr));
	sort(all(rx));
	sort(all(ry));
	set <pii> setx, sety;
	int idx = 0;
	while(idx < 2*m && G(arr[0], 0) >= G(rx[idx], 0)) {
		if(setx.find({G(rx[idx], 1), G(rx[idx], 2)}) == setx.end()) {
			setx.insert({G(rx[idx], 1), G(rx[idx], 2)});
		}
		else setx.erase({G(rx[idx], 1), G(rx[idx], 2)});
		idx++;
	}
	for(int i = 1; i < n; i++) {
		if(G(arr[i], 0) == G(arr[i-1], 0)) {
			if(setx.lower_bound({G(arr[i], 1), -1}) == setx.lower_bound({G(arr[i-1], 1), -1})) {
				g[G(arr[i], 2)].eb(G(arr[i-1], 2), abs(G(arr[i-1], 1)-G(arr[i], 1)));
				g[G(arr[i-1], 2)].eb(G(arr[i], 2), abs(G(arr[i-1], 1)-G(arr[i], 1)));
			}
		}
		while(idx < 2*m && G(arr[i], 0) >= G(rx[idx], 0)) {
			if(setx.find({G(rx[idx], 1), G(rx[idx], 2)}) == setx.end()) {
				setx.insert({G(rx[idx], 1), G(rx[idx], 2)});
			}
			else setx.erase({G(rx[idx], 1), G(rx[idx], 2)});
			idx++;
		}
	}
	sort(all(arr), [](tp3 a, tp3 b) {
		if(G(a, 1) == G(b, 1)) return a < b;
		return G(a, 1) < G(b, 1);
	});
	idx = 0;
	while(idx < 2*m && G(arr[0], 1) >= G(ry[idx], 0)) {
		if(sety.find({G(ry[idx], 1), G(ry[idx], 2)}) == sety.end()) {
			sety.insert({G(ry[idx], 1), G(ry[idx], 2)});
		}
		else sety.erase({G(ry[idx], 1), G(ry[idx], 2)});
		idx++;
	}
	for(int i = 1; i < n; i++) {
		if(G(arr[i], 1) == G(arr[i-1], 1)) {
			if(sety.lower_bound({G(arr[i], 0), -1}) == sety.lower_bound({G(arr[i-1], 0), -1})) {
				g[G(arr[i], 2)].eb(G(arr[i-1], 2), abs(G(arr[i-1], 0)-G(arr[i], 0)));
				g[G(arr[i-1], 2)].eb(G(arr[i], 2), abs(G(arr[i-1], 0)-G(arr[i], 0)));
			}
		}
		while(idx < 2*m && G(arr[i], 1) >= G(ry[idx], 0)) {
			if(sety.find({G(ry[idx], 1), G(ry[idx], 2)}) == sety.end()) {
				sety.insert({G(ry[idx], 1), G(ry[idx], 2)});
			}
			else sety.erase({G(ry[idx], 1), G(ry[idx], 2)});
			idx++;
		}
	}
 
	int cnt = 0;
	vector <int> E;
	vector <ll> sum(2*n+10);
	vector <bool> chk(n+10);
	for(int i = 0; i < n; i++) {
		if(chk[i]) continue;
		cnt++;
		priority_queue <pii, vector <pii>, greater <pii> > pq;
		pq.push({0, i});
		while(!pq.empty()) {
			int x = pq.top().se;
			int val = pq.top().fi;
			pq.pop();
			if(chk[x]) continue;
			chk[x] = true;
			E.eb(val);
			for(auto j : g[x]) {
				pq.push({j.se, j.fi});
			}
		}
	}
	sort(all(E));
	sum[0] = E[0];
	for(int i = 1; i < E.size(); i++) {
		sum[i] = sum[i-1] + (ll)E[i];
	}
	while(c--) {
		ll b, h;
		cin >> b >> h;
		if(h < cnt) {
			cout << "-1\n";
			continue;
		}
		int k = (int)(upper_bound(all(E), b) - E.begin());
		if(E.size() - k + cnt <= h) {
			if(k == 0) cout << b * n << '\n';
			else cout << sum[k-1] + (E.size() - k + cnt) * b << '\n';
		}
		else {
			cout << sum[E.size()-h-1+cnt] + h * b << '\n';
		}
	}
}