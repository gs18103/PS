#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back

using namespace std;
typedef pair <int, int> pii;

int arr[101010], brr[101010];
map <int, bool> chk;
map <int, vector <int>> g;

vector <int> val;

void dfs(int x) {
	if(chk[x]) return;
	chk[x] = true;
	val.eb(x);
	for(auto i : g[x]) {
		dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		brr[i] = arr[i];
	}
	sort(brr+1, brr+n+1);
	for(int i = 1; i <= n; i++) {
		if(arr[i] == brr[i]) chk[arr[i]] = true;
		else g[brr[i]].eb(arr[i]), chk[arr[i]] = false;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		if(!chk[arr[i]]) {
			val.clear();
			dfs(arr[i]);
			sort(val.begin(), val.end());
			long long tans = (long long)val[0] * (val.size()-1);
			if(val[0] != brr[1]) {
				tans = min(tans, (long long)brr[1] * (long long)(val.size() + 1) + 2 * val[0]);
			}
			ans += tans;
			for(int i = 1; i < val.size(); i++) {
				ans += val[i];
			}
		}
	}
	cout << ans;
}