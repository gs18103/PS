#include <bits/stdc++.h>

using namespace std;

int tree[5050505];


int update(int node, int s, int e, int k, int val) {
	if(s == e) return tree[node] = val;
	int m = s + e >> 1;
	if(k <= m) tree[node] = tree[node*2+1] * update(node*2, s, m, k, val);
	else tree[node] = tree[node*2] * update(node*2+1, m+1, e, k, val);
	return tree[node];
}

int cal(int node, int s, int e, int l, int r) {
	if(s > r || e < l) return 1;
	if(s >= l && e <= r) return tree[node];
	int m = s + e >> 1;
	return cal(node*2, s, m, l, r) * cal(node*2+1, m+1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	int n, k;
	while(cin >> n >> k) {
		for(int i = 1, u; i <= n; i++) {
			cin >> u;
			if(u > 0) update(1, 1, n, i, 1);
			else if(u < 0) update(1, 1, n, i, -1);
			else update(1, 1, n, i, 0);
		}
		string ans;
		while(k--) {
			string t;
			int i, j;
			cin >> t >> i >> j;
			if(t[0] == 'C') {
				if(j > 0) update(1, 1, n, i, 1);
				else if(j < 0) update(1, 1, n, i, -1);
				else update(1, 1, n, i, 0);
			}
			else {
				int flag = cal(1, 1, n, i, j);
				if(flag == 0) ans += "0";
				if(flag < 0) ans += "-";
				if(flag > 0) ans += "+";
			}
		}
		cout << ans << endl;
	}
}