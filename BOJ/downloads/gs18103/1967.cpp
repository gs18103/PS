#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int> > g[10101];
int maxd[10101];
bool chk[10101];

int f(int k) {
	for(int i = 0; i < g[k].size(); i++) {
		maxd[k] = max(maxd[k], f(g[k][i].first) + g[k][i].second);
	}
	return maxd[k];
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
	}
	f(1);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int m1 = 0, m2 = 0;
		for(int j = 0; j < g[i].size(); j++) {
			int td = maxd[g[i][j].first] + g[i][j].second;
			if(m1 < td) m2 = m1, m1 = td;
			else if(m2 < td) m2 = td;
		}
		ans = max(ans, m1 + m2);
	}
	printf("%d", ans);
}