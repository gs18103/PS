#include <bits/stdc++.h>

using namespace std;

int arr[505050], tree[505050], n;
vector <int> num;

void update(int i, int val) {
	while(i <= n) {
		tree[i] += val;
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
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		num.emplace_back(arr[i]);
	}
	sort(num.begin(), num.end());
	for(int i = 1; i <= n; i++) {
		arr[i] = lower_bound(num.begin(), num.end(), arr[i])-num.begin()+1;
	}

	for(int i = 1; i <= n; i++) {
		cout << i-cal(arr[i]) << '\n';
		update(arr[i], 1);
	}
}