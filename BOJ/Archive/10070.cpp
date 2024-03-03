#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define report(x, l, s) stype[x] = s, location[x] = l, chk[x] = true

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 2020202;
const int INF = 1e9;
const ll LINF = 1e18;

pii tree[4*MAX];
int op[505050], l[505050], r[505050], h[505050];
int ans[MAX];
int n, k;

void push(int node, int val, int t) {
    if(t == 1) {
        tree[node].fi = max(tree[node].fi, val);
        tree[node].se = max(tree[node].se, val);
    }
    else {
        tree[node].fi = min(tree[node].fi, val);
        tree[node].se = min(tree[node].se, val);
    }
}

void update(int node, int s, int e, int l, int r, int val, int t) {
	if(s > r || e < l) return;
	if(s >= l && e <= r) {
        push(node, val, t);
		return;
	}
    push(node<<1, tree[node].fi, 1);
    push(node<<1, tree[node].se, 2);
    push(node<<1|1, tree[node].fi, 1);
    push(node<<1|1, tree[node].se, 2);
	update(node<<1, s, s+e>>1, l, r, val, t);
	update(node<<1|1, (s+e>>1)+1, e, l, r, val, t);
	tree[node].fi = min(tree[node<<1].fi, tree[node<<1|1].fi);
	tree[node].se = max(tree[node<<1].se, tree[node<<1|1].se);
}

int cal(int node, int s, int e, int k) {
    if(s == e) return tree[node].fi;
    int m = s + e >> 1;
    if(k <= m) {
        push(node<<1, tree[node].fi, 1);
        push(node<<1, tree[node].se, 2);
        return cal(node<<1, s, m, k);
    }
    else {
        push(node<<1|1, tree[node].fi, 1);
        push(node<<1|1, tree[node].se, 2);
        return cal(node<<1|1, m+1, e, k);
    }
}

void buildWall() {
	for(int i = 0; i < k; i++) {
		update(1, 0, n-1, l[i], r[i], h[i], op[i]);
	}
	for(int i = 0; i < n; i++) {
		ans[i] = cal(1, 0, n-1, i);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;

	for (int i = 0; i < k; i++){
		cin >> op[i] >> l[i] >> r[i] >> h[i];
	}

	buildWall();

	for (int j = 0; j < n; j++) {
		cout << ans[j] << '\n';
	}
	
	return 0;
}
