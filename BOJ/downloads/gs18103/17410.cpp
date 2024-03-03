#include <bits/stdc++.h>
#define eb emplace_back
#define all(v) v.begin(), v.end()

using namespace std;

const int sz = 350;
int arr[101010];
vector <int> bucket[300];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		bucket[(i+sz-1)/sz].eb(arr[i]);
	}
	for(int i = 0; i <= (n + sz - 1) / sz; i++) {
		sort(all(bucket[i]));
	}

	int q;
	cin >> q;
	while(q--) {
		int t;
		cin >> t;
		if(t == 2) {
			int u, v, k, ans = 0;
			cin >> u >> v >> k;
			if((u+2*sz-2)/sz > v/sz) {
				for(int i = u; i <= v; i++) {
					if(arr[i] > k) ans++;
				}
				cout << ans << '\n';
				continue;
			}
			for(int i = (u+2*sz-2)/sz; i <= v/sz; i++) {
				ans += bucket[i].end() - upper_bound(all(bucket[i]), k);
			}
			for(int i = u; i <= ((u+sz-2)/sz)*sz; i++) {
				if(arr[i] > k) ans++;
			}
			for(int i = v; i > (v/sz)*sz; i--) {
				if(arr[i] > k) ans++;
			}
			cout << ans << '\n';
		}
		if(t == 1) {
			int u, v;
			cin >> u >> v;
			int k = lower_bound(all(bucket[(u+sz-1)/sz]), arr[u])-bucket[(u+sz-1)/sz].begin();
			arr[u] = v;
			bucket[(u+sz-1)/sz][k] = v;
			while(k > 0 && bucket[(u+sz-1)/sz][k-1] > bucket[(u+sz-1)/sz][k]) {
				swap(bucket[(u+sz-1)/sz][k-1], bucket[(u+sz-1)/sz][k]);
				k--;
			}
			while(k+1 < bucket[(u+sz-1)/sz].size() && bucket[(u+sz-1)/sz][k+1] < bucket[(u+sz-1)/sz][k]) {
				swap(bucket[(u+sz-1)/sz][k+1], bucket[(u+sz-1)/sz][k]);
				k++;
			}
		}
	}
}