#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair <ll, int> pll;

ll arr[101010], ans[101010];
int tree[101010], n;

void update(int i) {
	while(i <= n) {
		tree[i]++;
		i += (i & -i);
	}
}

int cal(int i) {
	int ret = 0;
	while(i) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	priority_queue <pll, vector <pll>, greater <pll> > pq;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		pq.push({arr[i], i});
	}

	ll pre = 0, tm = 0;
	while(!pq.empty()) {
		pll t = pq.top();
		pq.pop();
		tm += (t.fi - pre - 1) * (n-cal(n));
		pre = t.fi;
		ans[t.se] = tm + t.se - cal(t.se);
		queue <int> query;
		query.push(t.se);
		while(!pq.empty() && pq.top().fi == t.fi) {
			pll temp = pq.top();
			pq.pop();
			ans[temp.se] = tm + temp.se - cal(temp.se);
			query.push(temp.se);
		}
		tm += n-cal(n);
		while(!query.empty()) {
			int x = query.front();
			query.pop();
			update(x);
		}
	}

	for(int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}