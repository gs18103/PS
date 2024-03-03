#include <bits/stdc++.h>
#define x first
#define y second
 
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;
 
vector <pll> p, ch;
pll base;

ll ccw(pll a, pll b, pll c) {
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

ll dist(pll a, pll b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	p.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}

	sort(p.begin(), p.end());
	base = p[0];
	sort(p.begin()+1, p.end(), [](pll a, pll b) {
        if(ccw(base, a, b) == 0) return dist(base, a) < dist(base, b);
		return ccw(base, a, b) > 0;
	});
	ch.push_back(base);
	for(int i = 1; i < n; i++) {
		while(ch.size() >= 2) {
			pll p1 = ch[ch.size()-2], p2 = ch[ch.size()-1];
			if(ccw(p1, p2, p[i]) > 0) break;
			ch.pop_back();
		}
		ch.push_back(p[i]);
	}
	cout << ch.size();
}