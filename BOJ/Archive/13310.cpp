#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
 
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;
 
ll arr[30303][4];
pll base;
int n, T;

ll ccw(pll a, pll b, pll c) {
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

ll dis(pll a, pll b) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

ll cal_dis(int t) {
	vector <pll> p, ch;
	for(int i = 0; i < n; i++) {
		p.emplace_back(arr[i][0] + arr[i][2] * (ll)t, arr[i][1] + arr[i][3] * (ll)t);
	}
	sort(all(p));
	p.erase(unique(all(p)), p.end());
	if(p.size() == 1) return 0;
	base = p[0];
	sort(p.begin()+1, p.end(), [](pll a, pll b) {
		if(ccw(base, a, b) == 0) return dis(base, a) < dis(base, b);
		return ccw(base, a, b) > 0;
	});
	ch.push_back(base);
	for(int i = 1; i < p.size(); i++) {
		while(ch.size() >= 2) {
			pll p1 = ch[ch.size()-2], p2 = ch[ch.size()-1];
			if(ccw(p1, p2, p[i]) > 0) break;
			ch.pop_back();
		}
		ch.push_back(p[i]);
	}

	ll ret = 0;
	for(int i = 0; i < ch.size(); i++) {
		if(i+1 < ch.size() && ch[i+1].x < ch[i].x) break;
		int lb = i, ub = ch.size()-1;
		while(lb + 10 < ub) {
			int m1 = (2 * lb + ub) / 3, m2 = (lb + 2 * ub) / 3;
			if(dis(ch[m1], ch[i]) > dis(ch[m2], ch[i])) ub = m2;
			else lb = m1;
		}
		for(int j = lb; j <= ub; j++) {
			if(dis(ch[i], ch[lb]) < dis(ch[i], ch[j])) lb = j;
		}
		ret = max(ret, dis(ch[i], ch[lb]));
	}
	return ret;
}

int search(int s, int e) {
	if(s + 10 >= e) 	{
		ll dis = 9000000000000000000LL;
		for(int i = s; i <= e; i++) {
			dis = min(dis, cal_dis(i));
		}
		for(int i = s; i <= e; i++) {
			if(dis == cal_dis(i)) return i;
		}
	}
	int t1 = (2 * s + e) / 3, t2 = (s + 2 * e) / 3;
	ll dis1 = cal_dis(t1), dis2 = cal_dis(t2);
	if(dis1 <= dis2) return search(s, t2);
	else return search(t1, e);
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> T;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = search(0, T);
	cout << ans << endl << cal_dis(ans);
}