#include <bits/stdc++.h>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;
typedef long long ll;

int arr[1030][1030];
int tree[1030][1030];

void update(int n, int i, int j, ll val) {
	int k = j;
	while(i <= n) {
		j = k;
		while(j <= n) {
			tree[i][j] += val;
			j += (j & -j);
		}
		i += (i & -i);
	}
}

ll cal(int i, int j) {
	ll ret = 0;
	int k = j;
	while(i) {
		j = k;
		while(j) {
			ret += tree[i][j];
			j -= (j & -j);
		}
		i -= (i & -i);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			update(n, i, j, arr[i][j]);
		}
	}

	while(q--) {
		int t;
		cin >> t;
		if(t) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << cal(x2, y2) - cal(x2, y1-1) - cal(x1-1, y2) + cal(x1-1, y1-1) << '\n';
		}
		else {
			int x, y, c;
			cin >> x >> y >> c;
			update(n, x, y, c - arr[x][y]);
			arr[x][y] = c;
		}
	}
}