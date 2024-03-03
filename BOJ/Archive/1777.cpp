#include <bits/stdc++.h>

using namespace std;

int per[303030];
int tree[303030];

void update(int n, int i, int val) {
	while(i <= n) {
		tree[i] += val;
		i += (i &-i);
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

int arr[303030];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = n; i >= 1; i--) {
		int u = arr[i], lb = 1, ub = n;
		while(lb < ub) {
			int m = lb + ub + 1 >> 1;
			if(m-1-cal(m-1) > u) ub = m-1;
			else lb = m;
		}
		per[lb] = i;
		update(n, lb, 1);
	}
	for(int i = n; i >= 1; i--) {
		cout << per[i] << ' ';
	}
}