#include <bits/stdc++.h>

using namespace std;

int n, m;
int px[303030];
int py[303030];
long long x[303030];
long long y[303030];
long long tree[1204040];

void update(int i, int val) {
	while(i <= m) {
		tree[i] += val;
		i += (i & -i);
	}
}

long long sum(int i) {
	long long ans = 0;
	while(i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %lld", &px[i], &x[i]);
	}

	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d %lld", &py[i], &y[i]);
	}

	for(int i = 1; i <= m; i++) {
		update(i, y[i]);
	}

	int a, b;
	long long ans = 0;
	scanf("%d %d", &a, &b);
	for(int i = 1; i <= n; i++) {
		int s, e;
		s = (int)(lower_bound(py + 1, py + m + 1, px[i] + a) - py);
		e = (int)(upper_bound(py + 1, py + m + 1, px[i] + b) - py) - 1;
		if(e > m) e = m;
		ans += x[i] * (sum(e) - sum(s-1));
	}
	printf("%lld\n", ans);
}