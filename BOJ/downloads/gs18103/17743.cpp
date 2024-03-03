#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define fi first
#define se second
#define INF 2000000000
#define LINF 1000000000000000000LL
 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
void update(auto &tree, auto &cnt, int x, int n) {
	x += (1 << n) - 1;
	tree[x] = (tree[x] + 1) % 2;
	for(int i = n - 1; i >= 0; i--) {
		x >>= 1;
		if(tree[x] == (1 << (n-i)) || tree[x] == 0) cnt[i]++;
		tree[x] = tree[x*2] + tree[x*2+1];
		if(tree[x] == (1 << (n-i)) || tree[x] == 0) cnt[i]--;
	}
}
 
int main() {
	fastio;
	vector <ll> treex, treey, cntx, cnty;
	int n, q;
	cin >> n >> q;
	treex.resize((1<<(n+1))+10);
	treey.resize((1<<(n+1))+10);
	cntx.resize(n+10);
	cnty.resize(n+10);
 
	while(q--) {
		int t, x;
		cin >> t >> x;
		if(t) update(treex, cntx, x, n);
		else update(treey, cnty, x, n);
		ll ans = 0;
		for(int i = 0; i < n; i++) {
			ans += (1LL<<i) * (cntx[i] + cnty[i]) - cntx[i] * cnty[i];
		}
		cout << ans * 4 + 1 << '\n';
	}
}