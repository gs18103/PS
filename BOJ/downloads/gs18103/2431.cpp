#include <bits/stdc++.h>

using namespace std;

double x[101010];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout << fixed; cout.precision(6);

	int m, n;
	cin >> m >> n;
	for(int i = 1; i <= n; i++) {
		string t;
		cin >> x[i] >> t;
	}
	sort(x+1, x+n+1);
	double d = 2.0 * m / n, mx = 0.0, mi = 2.0*m;
	for(int i = 1; i <= n; i++) {
		double t = d * (i / 2) - x[i];
		if(i & 1) t *= -1;
		mx = max(mx, t);
		mi = min(mi, t);
	}
	cout << (mx - mi) / 2;
}