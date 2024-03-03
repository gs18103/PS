#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll B[101010], C[101010], L[101010], ans = 0, sum[101010], m;
vector <int> g[101010];
priority_queue <ll> pq[101010];
int dfs(int x) {
	vector <int> idx;
	for(auto i : g[x]) {
		idx.eb(dfs(i));
	}
	int ret = x;
	pq[ret].push(C[x]);
	sum[ret] = C[x];
	for(auto i : idx) {
		if(pq[ret].size() < pq[i].size()) {
			while(!pq[ret].empty()) {
				pq[i].push(pq[ret].top());
				pq[ret].pop();
			}
			sum[i] += sum[ret];
			ret = i;
		}
		else {
			while(!pq[i].empty()) {
				pq[ret].push(pq[i].top());
				pq[i].pop();
			}
			sum[ret] += sum[i];
		}
	}
	while(!pq[ret].empty() && sum[ret] > m) {
		sum[ret] -= pq[ret].top();
		pq[ret].pop();
	}
	ans = max(ans, (ll)(L[x] * pq[ret].size()));
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> B[i] >> C[i] >> L[i];
		g[B[i]].eb(i);
	}
	dfs(1);
	cout << ans;
}