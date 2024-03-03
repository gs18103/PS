#include <bits/stdc++.h>
#define mod 10007

using namespace std;
typedef long long ll;

int a[101010], tree[300000][20], c;

void update(int node, int s, int e, int k, int va, int vb) {
	if(s == e) {
		tree[node][1] = va % mod;
		tree[node][0] = vb % mod;
		return;
	}
	int m = s + e >> 1;
	if(k <= m) update(node*2, s, m, k, va, vb);
	else update(node*2+1, m+1, e, k, va, vb);
	for(int i = 0; i < c; i++) {
		tree[node][i] = 0;
		for(int j = 0; j <= i; j++) {
			tree[node][i] += tree[node*2][j] * tree[node*2+1][i-j];
			tree[node][i] %= mod;
		}
	}
}

int mtree[404040];

int mupdate(int node, int s, int e, int k, int val) {
	if(s == e) return mtree[node] = val % mod;
	int m = s + e >> 1;
	if(k <= m) return mtree[node] = (mtree[node*2+1] * mupdate(node*2, s, m, k, val)) % mod;
	else return mtree[node] = (mtree[node*2] * mupdate(node*2+1, m+1, e, k, val)) % mod;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n >> c;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		int b;
		cin >> b;
		update(1, 1, n, i, a[i], b);
		mupdate(1, 1, n, i, a[i] + b);
	}

	int q;
	cin >> q;
	while(q--) {
		int p, ap, bp;
		cin >> p >> ap >> bp;
		update(1, 1, n, p, ap, bp);
		mupdate(1, 1, n, p, ap + bp);
		int ans = mtree[1];
		for(int i = 0; i < c; i++) {
			ans += (mod - tree[1][i]) % mod;
			ans %= mod;
		}
		cout << ans << '\n';
	}
}