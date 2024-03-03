#include <bits/stdc++.h>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define g(tp, x) get<x>(tp)

using namespace std;
typedef long long ll;

struct point {
    int x, y;
    ll val;
};

struct SEG {
    struct Node {
		ll l = 0, r = 0, v = 0, s = 0;
	};

	Node tree[12020];
	void init() {
		for(int i = 0; i <= 12000; i++) {
			tree[i].l = tree[i].r = tree[i].s = tree[i].v = 0;
		}
	}
	void update(int node, int s, int e, int k, int diff) {
		if(s == e) {
			tree[node].l = tree[node].r = tree[node].v = tree[node].s += diff;
			tree[node].l = max(0LL, tree[node].l);
			tree[node].r = max(0LL, tree[node].r);
			return;
		}
		int m = s + e >> 1;
		if(k <= m) update(node*2, s, m, k, diff);
		else update(node*2+1, m+1, e, k, diff);
		tree[node].l = max(tree[node*2].s + tree[node*2+1].l, tree[node*2].l);
		tree[node].r = max(tree[node*2].r + tree[node*2+1].s, tree[node*2+1].r);
		tree[node].s = tree[node*2].s + tree[node*2+1].s;
		tree[node].v = max(tree[node*2].v, tree[node*2+1].v);
		tree[node].v = max(tree[node].v, tree[node*2].r + tree[node*2+1].l);
	}
} st;

vector <int> X, Y;
point arr[3030];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n1, n2, c1, c2;
    cin >> n1;
    for(int i = 1; i <= n1; i++) {
        cin >> arr[i].x >> arr[i].y;
        Y.eb(arr[i].y);
    }
    cin >> n2;
    for(int i = n1 + 1; i <= n1 + n2; i++) {
        cin >> arr[i].x >> arr[i].y;
        Y.eb(arr[i].y);
    }
    int n = n1 + n2;
    cin >> c1 >> c2;
    for(int i = 1; i <= n1; i++) {
        arr[i].val = c1;
    }
    for(int i = n1 + 1; i <= n; i++) {
        arr[i].val = -c2;
    }
    sort(all(Y));
    sort(arr+1, arr+n+1, [](point a, point b) {
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });
    for(int i = 1; i <= n; i++) {
        arr[i].y = lower_bound(all(Y), arr[i].y)-Y.begin()+1;
    }

    ll ans = -1000000000000000000;
    for(int i = 1; i <= n; i++) {
        if(i < n && arr[i].x == arr[i+1].x) continue;
        st.init();
        for(int j = i; j >= 1; j--) {
            st.update(1, 1, n, arr[j].y, arr[j].val);
            while(j > 1 && arr[j-1].x == arr[j].x) {
                j--;
                st.update(1, 1, n, arr[j].y, arr[j].val);
            }
            ans = max(ans, st.tree[1].v);
        }
    }
    cout << ans;
}
