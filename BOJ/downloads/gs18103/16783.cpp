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

const int MAX = 1010;
const int INF = 1e9;
const ll LINF = 9e18;

class SegmentTree {
    struct Node {
        ll lmx = 0, rmx = 0, mx = 0, s = 0;
        Node operator + (Node b) {
            Node ret;
            ret.lmx = max(lmx, s + b.lmx);
            ret.rmx = max(b.rmx, b.s + rmx);
            ret.mx = max({mx, b.mx, rmx + b.lmx});
            ret.s = s + b.s;
            return ret;
        }
    };
    vector <Node> tree;
    int sz;
public:

    void Init(int n) {
        tree.resize(4*n+10);
        sz = n;
    }

    void Update(int k, ll val) {
        update(1, 0, sz-1, k, val);
    }
    void update(int node, int s, int e, int k, ll val) {
        if(s == e) {
            tree[node].lmx = tree[node].rmx = tree[node].mx = max(0LL, val);
            tree[node].s = val;
            return;
        }
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, val);
        else update(node<<1|1, m+1, e, k, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    ll get() {
        return tree[1].mx;
    }
};

struct Point {
    int x, y;
    ll val;
    bool operator < (const Point &p) const {
        return pii(x, y) < pii(p.x, p.y);
    }
};

struct Evt{
	int dx, dy, idx1, idx2;
    Evt(int dx, int dy, int idx1, int idx2) : dx(dx), dy(dy), idx1(idx1), idx2(idx2) {}
	bool operator < (const Evt &s)const{
		ll k = 1ll * dx * s.dy - 1ll * dy * s.dx;
		if(k == 0) return pii(idx1, idx2) < pii(s.idx1, s.idx2);
        return k > 0;
	}
};

ll ccw(Evt a, Evt b) {
    return (ll)a.dx * b.dy - (ll)b.dx * a.dy;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <Point> a(n);
    vector <int> pos(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].val;
    }

    if(n == 1) {
        cout << max(0LL, a[0].val) << endl;
        return 0;
    }
    sort(all(a));
    for(int i = 0; i < n; i++) {
        pos[i] = i;
    }

    vector <Evt> line;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            line.eb(a[j].x - a[i].x, a[j].y - a[i].y, i, j);
        }
    }
    sort(all(line));

    SegmentTree ST;
    ST.Init(n);
    for(int i = 0; i < n; i++) {
        ST.Update(i, a[i].val);
    }

    ll ans = 0;
    for(int i = 0; i < line.size(); i++) {
        int rx = pos[line[i].idx1], ry = pos[line[i].idx2];
        swap(a[rx], a[ry]);
        swap(pos[line[i].idx1], pos[line[i].idx2]);
        ST.Update(rx, a[rx].val);
        ST.Update(ry, a[ry].val);
        if(i + 1 < line.size() && ccw(line[i], line[i+1]) == 0) continue;
        ans = max(ans, ST.get());
    }
    cout << ans << endl;
}