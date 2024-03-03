#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef pair <int, int> pii;

struct row {
	int x, y, z;
};

row arr[202020];
int dp[202020], M, n;

struct Fwt {
	int tree[202020];

	void init(int k) {
		for(int i = 0; i <= k+10; i++) tree[i] = 0;
	}

	void update(int i, int val) {
		while(i <= n) {
			tree[i] = max(tree[i], val);
			i += (i & -i);
		}
	}
	int cal(int i) {
		int ret = 0;
		while(i > 0) {
			ret = max(ret, tree[i]);
			i -= (i & -i);
		}
		return ret;
	}
} fwt;

void dnc(int s, int e) {
	if(s == e) {
		dp[s] = max(dp[s], 1);
		return;
	}
	int m = s + e >> 1;
	dnc(s, m);

	vector <row> l, r;
	vector <int> X, Y;
	for(int i = s; i <= m; i++) {
		l.eb(arr[i]), X.eb(arr[i].x), Y.eb(arr[i].y);
	}
	for(int i = m+1; i <= e; i++) {
		r.eb(arr[i]), X.eb(arr[i].x), Y.eb(arr[i].y);
	}
	sort(all(l), [](row a, row b) {
		return a.x < b.x;
	});
	sort(all(r), [](row a, row b) {
		return a.x < b.x;
	});
	sort(all(X)), sort(all(Y));
	for(int i = 0; i < l.size(); i++) {
		l[i].x = lower_bound(all(X), l[i].x)-X.begin()+1;
		l[i].y = lower_bound(all(Y), l[i].y)-Y.begin()+1;
	}
	for(int i = 0; i < r.size(); i++) {
		r[i].x = lower_bound(all(X), r[i].x)-X.begin()+1;
		r[i].y = lower_bound(all(Y), r[i].y)-Y.begin()+1;
	}
	fwt.init(X.size());
	int idx = 0;
	for(int i = 0; i < r.size(); i++) {
		while(idx < l.size() && l[idx].x < r[i].x) {
			fwt.update(l[idx].y, dp[l[idx].z]);
			idx++;
		}
		dp[r[i].z] = max(dp[r[i].z], fwt.cal(r[i].y-1) + 1);
	}
	dnc(m+1, e);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> M >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i].x;
	}
	for(int i = 1; i <= n; i++) {
		cin >> arr[i].y;
	}
	for(int i = 1; i <= n; i++) {
		if(M == 3) cin >> arr[i].z;
		else arr[i].z = arr[i].y;
	}

	sort(arr+1, arr+n+1, [](row a, row b) {
		return a.z < b.z;
	});
	for(int i = 1; i <= n; i++) {
		arr[i].z = i;
	}
	dnc(1, n);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}