#include <bits/stdc++.h>

using namespace std;

int x[1010], y[1010];
int dp[1010][1010];
int n, w;

int f(int p1, int p2) {
	if(p1 == w || p2 == w) return 0;
	if(dp[p1][p2] != 0) return dp[p1][p2];
	int d1, d2, t = max(p1, p2) + 1;
	
	if(p1 == 0) d1 = abs(x[t] - 1) + abs(y[t] - 1);
	else d1 = abs(x[t] - x[p1]) + abs(y[t] - y[p1]);

	if(p2 == 0) d2 = abs(x[t] - n) + abs(y[t] - n);
	else d2 = abs(x[t] - x[p2]) + abs(y[t] - y[p2]);

	int f1 = f(t, p2) + d1, f2 = f(p1, t) + d2;
	return dp[p1][p2] = min(f1, f2);
}

int main() {
	scanf("%d %d", &n, &w);
	for(int i = 1; i <= w; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	printf("%d\n", f(0, 0));

	int p1 = 0, p2 = 0, d1, d2;
	while(p1 != w && p2 != w) {
		int t = max(p1, p2) + 1;
		if(p1 == 0) d1 = abs(x[t] - 1) + abs(y[t] - 1);
		else d1 = abs(x[t] - x[p1]) + abs(y[t] - y[p1]);

		if(p2 == 0) d2 = abs(x[t] - n) + abs(y[t] - n);
		else d2 = abs(x[t] - x[p2]) + abs(y[t] - y[p2]);
		
		if(dp[p1][p2] == dp[p1][t] + d2) {
			printf("2\n");
			p2 = t;
		}
		else {
			printf("1\n");
			p1 = t;
		}
	}
}