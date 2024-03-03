#include <bits/stdc++.h>
#define eb emplace_back

using namespace std;
typedef long long ll;

const ll n = (1LL<<32)-1;
ll XOR = 0;

struct Node {
	ll l, r, val;
	Node(ll l, ll r, ll val) : l(l), r(r), val(val) {} ;
};

vector <Node> tree;

void update(ll node, ll s, ll e, ll k, ll v) {
	tree[node].val += v;
	if(s == e) return;
	ll m = s + e >> 1;
	if(k <= m) {
		if(tree[node].l == 0) {
			tree[node].l = tree.size();
			tree.eb(0, 0, 0);
		}
		update(tree[node].l, s, m, k, v);
	}
	else {
		if(tree[node].r == 0) {
			tree[node].r = tree.size();
			tree.eb(0, 0, 0);
		}
		update(tree[node].r, m+1, e, k, v);
	}
}

ll cal(ll node, ll s, ll e, ll x) {
	if(s == e) return s ^ XOR;
	ll cntl = tree[tree[node].l].val, cntr = tree[tree[node].r].val;
	ll m = s + e >> 1;
	if(x & (((e-s+1)>>1) ^ XOR)) {
		if(cntl > 0) return cal(tree[node].l, s, m, x);
		else return cal(tree[node].r, m+1, e, x);
	}
	else {
		if(cntr > 0) return cal(tree[node].r, m+1, e, x);
		else return cal(tree[node].l, s, m, x);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	ll q, XOR = 0;
	cin >> q;
	tree.eb(0, 0, 0);
	tree.eb(0, 0, 0);
    update(1, 0, n, 0, 1);
	for(int i = 0; i < q; i++) {
		ll a, x;
		cin >> a >> x;
		if(a == 1) update(1, 0, n, x, 1);
		if(a == 2) update(1, 0, n, x, -1);
		if(a == 3) {
			cout << (x ^ cal(1, 0, n, x)) << '\n';
			XOR ^= x;
		}
	}
}