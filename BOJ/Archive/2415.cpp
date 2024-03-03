#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll ccw(pll a, pll b, pll c) {
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

ll dot(pll a, pll b, pll c) {
	return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}

int n;
pll arr[2020], base;
vector <pll> p;
set <pll> s;

void read() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
		s.insert(arr[i]);
		p.eb(arr[i]);
	}
}

ll dis(pll a) {
	return (a.x-base.x)*(a.x-base.x)+(a.y-base.y)*(a.y-base.y);
}

ll get_ans() {
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		base = arr[i];
		sort(all(p), [](pll a, pll b){
			if(a == base) return true;
			if(b == base) return false;
			if(b.x > base.x && a.x <= base.x) return true;
			if(a.x > base.x && b.x <= base.x) return false;
			if(a.x == base.x && b.x == base.x) return a > b;
			return ccw(base, a, b) > 0;
		});
		int idx = 1;
		for(int j = 1; j < n; j++) {
			while(idx+1 < 2 * n && dot(base, p[j], p[idx%n]) > 0) {
				idx++;
				if(idx == n) idx++;
			}
			while(dot(base, p[j], p[idx%n]) == 0 && idx < 2 * n) {
				pll temp = {0, 0};
				temp.x = p[j].x + p[idx%n].x - base.x;
				temp.y = p[j].y + p[idx%n].y - base.y;
				if(s.find(temp) != s.end()) ans = max(ans, abs(ccw(base, p[j], p[idx%n])));
				if(dot(base, p[j], p[(idx+1)%n]) == 0 && idx+1 < 2 * n) idx++;
				else break;
				if(idx == n) idx++;
			}
		}
	}
	return ans;
}

int main() {
	read();
	cout << get_ans();
}