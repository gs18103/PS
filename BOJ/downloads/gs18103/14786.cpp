#include <bits/stdc++.h>
#define PI (4.0*atan(1.0))

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout << fixed; cout.precision(10);

	double a, b, c;
	cin >> a >> b >> c;
	double lb = 0, ub = PI;
	int cnt = 0;
	while(ub < c / a) ub += PI, lb += PI;
	for(int i = 0; i < 40; i++) {
		double m = (lb + ub) / 2.0;
		if(c - a * m > b * sin(m)) lb = m;
		else ub = m;
	}
	cout << (lb + ub) / 2.0;
}