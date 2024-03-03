#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 505050;
const int INF = INT_MAX >> 1;
const ll LINF = LLONG_MAX >> 1;
const ll mod = 1e9+9;

struct Node {
	int l, r, val;
	Node(int l, int r, int val) : l(l), r(r), val(val) {}
};

int n, root[MAX], h[MAX];
vector <Node> tree;
vector <int> num, numx;
pii arr[MAX];

void expand_tree(int s, int e, int k, int pnd, int cnd) {
	tree[cnd].val = tree[pnd].val + 1;
	if(s == e) return;
	int m = s + e >> 1;
	if(k <= m) {
		tree[cnd].r = tree[pnd].r;
		tree[cnd].l = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(s, m, k, tree[pnd].l, tree[cnd].l);
	}
	else {
		tree[cnd].l = tree[pnd].l;
		tree[cnd].r = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(m+1, e, k, tree[pnd].r, tree[cnd].r);
	}
}

void init(int N, int A[], int B[]) {
	n = N;
	for(int i = 0; i < n; i++) {
		arr[i] = make_pair(A[i], B[i]);
		num.eb(B[i]);
		numx.eb(A[i]);
	}
	sort(all(num));
	sort(all(numx));
	sort(arr, arr+n, [](pii a, pii b) {
		if(a.se == b.se) return a.fi < b.fi;
		return a.se < b.se;
	});
	for(int i = 0; i < n; i++) {
		arr[i].se = i + 1;
	}
	sort(arr, arr+n);
	tree.eb(0, 0, 0);
	for(int i = 0; i < n; i++) {
		root[i+1] = tree.size();
		tree.eb(0, 0, 0);
		expand_tree(1, n, arr[i].se, root[i], root[i+1]);
	}
	return;
}

int cal(int s, int e, int l, int r, int pnd, int cnd) {
	if(s > r || e < l || l > r) return 0;
	if(s >= l && e <= r) return tree[cnd].val - tree[pnd].val;
	int m = s + e >> 1;
	return cal(s, m, l, r, tree[pnd].l, tree[cnd].l)
		+ cal(m+1, e, l, r, tree[pnd].r, tree[cnd].r);
}

int get_r(int s, int e, int cnt, int pnd, int cnd) {
	if(s == e) return s;
	int m = s + e >> 1, lcnt = tree[tree[cnd].l].val - tree[tree[pnd].l].val;
	if(lcnt >= cnt) return get_r(s, m, cnt, tree[pnd].l, tree[cnd].l);
	else return get_r(m+1, e, cnt - lcnt, tree[pnd].r, tree[cnd].r);
}

int can(int M, int K[]) {
	ll temp = 0;
	for(int i = 0; i < M; i++) temp += K[i];
	if(temp > n) return 0;

	sort(K, K+M);
	stack <pii> stk;
	stk.em(0, n+1);
	for(int i = 0; i < M; i++) {
		int last = lower_bound(all(num), K[i]) - num.begin() + 1, cnt = K[i];
		int rx = upper_bound(all(numx), K[i]) - numx.begin();
		while(!stk.empty() && stk.top().se < last) stk.pop();
		while(!stk.empty()) {
			int x = stk.top().fi, y = stk.top().se;
			int temp = cal(1, n, last, y, root[x], root[rx]);
			if(temp < cnt) {
				cnt -= temp;
				last = y + 1;
				stk.pop();
			}
			else {
				int l = cal(1, n, 1, last - 1, root[x], root[rx]);
				int ny = get_r(1, n, l + cnt, root[x], root[rx]);
				stk.em(rx, ny);
				break;
			}
		}
		if(stk.empty()) return 0;
	}
	return 1;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N;
    cin >> N;
    int *A = (int*)malloc(sizeof(int)*(unsigned int)N);
    int *B = (int*)malloc(sizeof(int)*(unsigned int)N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    init(N, A, B);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
    	int M;
        cin >> M;
	int *K = (int*)malloc(sizeof(int)*(unsigned int)M);
    	for (int j = 0; j < M; ++j) {
            cin >> K[j];
    	}
        cout << can(M, K) << '\n';
    }
    return 0;
}