#include <bits/stdc++.h>

using namespace std;

map <string, string> p;
map <string, int> cnt;

string find(string x) {
	if(p[x] == x) return p[x];
	else return p[x] = find(p[x]);
}

void uni(string x, string y) {
	x = find(x); y = find(y);
	if(x == y) return;
	p[max(x, y)] = min(x, y);
	cnt[min(x, y)] += cnt[max(x, y)];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int q;
	cin >> q;
	while(q--) {
		p.clear();
		cnt.clear();
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			string u, v;
			cin >> u >> v;
			if(p.find(u) == p.end()) p.insert({u, u}), cnt.insert({u, 1});
			if(p.find(v) == p.end()) p.insert({v, v}), cnt.insert({v, 1});
			uni(u, v);
			cout << cnt[find(u)] << '\n';
		}
	}
}