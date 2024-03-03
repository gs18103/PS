#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

class SegmentTree {
    struct Node {
		int l = 0, r = 0, v = 0;
        bool s = false;
        Node() {}
        Node operator + (Node b) {
            Node ret;
            if(s) ret.l = l + b.l;
            else ret.l = l;
            if(b.s) ret.r = r + b.r;
            else ret.r = b.r;
            ret.v = max(v, b.v);
            ret.v = max(ret.v, r + b.l);
            if(s && b.s) ret.s = true;
            return ret;
        }
	};
    vector <Node> tree;
    int sz;
public:
	void Init(int n) {
        sz = n;
        tree.resize(4*n+100);
	}
    void add(int k) {
        update(1, 1, sz, k, 1);
    }
    void clear() {
        for(auto &i : tree) {
            i.s = i.r = i.l = i.v = 0;
        }
    }
	void update(int node, int s, int e, int k, int val) {
		if(s == e) {
			tree[node].l = tree[node].r = tree[node].v += val;
            tree[node].s = true;
			return;
		}
		int m = s + e >> 1;
		if(k <= m) update(node<<1, s, m, k, val);
		else update(node<<1|1, m+1, e, k, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
	}
    int mx(int l, int r) {
        return cal(1, 1, sz, l, r).v;
    }
    Node cal(int node, int s, int e, int l, int r) {
        if(s > r || e < l) return Node();
        if(s >= l && e <= r) return tree[node];
        int m = s + e >> 1;
        return cal(node<<1, s, m, l, r) + cal(node<<1|1, m+1, e, l, r);
    }
};

struct Query {
    int l, r, w, idx;
    int lb = 0, ub = 100000;
    bool operator < (Query b) {
        return lb + ub > b.lb + b.ub;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector <pii> h(n);
    vector <int> num(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i].fi;
        h[i].se = i + 1;
        num[i] = h[i].fi;
    }
    sort(all(num));
    for(int i = 0; i < n; i++) {
        h[i].fi = lower_bound(all(num), h[i].fi) - num.begin();
    }
    sort(all(h));
    reverse(all(h));
    cin >> q;
    vector <ll> ans(q);
    vector <Query> Q(q);
    for(int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r >> Q[i].w;
        Q[i].ub = num.size()-1;
        Q[i].idx = i;
    }
    SegmentTree ST;
    ST.Init(n);

    bool flag = false;
    while(!flag) {
        sort(all(Q));
        ST.clear();

        flag = true;
        int idx = 0;
        for(auto &i : Q) {
            if(i.lb == i.ub) continue;
            flag = false;
            int m = (i.lb + i.ub + 1) / 2;
            while(idx < h.size() && h[idx].fi >= m) {
                ST.add(h[idx].se);
                idx++;
            }
            if(ST.mx(i.l, i.r) >= i.w) i.lb = m;
            else i.ub = m - 1;
        }
    }

    for(auto i : Q) {
        ans[i.idx] = num[i.lb];
    }
    for(int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}