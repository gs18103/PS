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
        int lmx = 0, rmx = 0, mx = 0;
        bool f = false;
        Node operator + (Node b) {
            Node ret;
            if(f) ret.lmx = lmx + b.lmx;
            else ret.lmx = lmx;
            if(b.f) ret.rmx = rmx + b.rmx;
            else ret.rmx = b.rmx;
            if(f && b.f) ret.f = true;
            ret.mx = max({mx, b.mx, rmx + b.lmx});
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

    void Update(int k, bool f) {
        update(1, 0, sz-1, k, f);
    }
    void update(int node, int s, int e, int k, bool f) {
        if(s == e) {
            if(f) tree[node].f = true, tree[node].lmx = tree[node].rmx = tree[node].mx = 1;
            else tree[node].f = false, tree[node].lmx = tree[node].rmx = tree[node].mx = 0;
            return;
        }
        int m = s + e >> 1;
        if(k <= m) update(node<<1, s, m, k, f);
        else update(node<<1|1, m+1, e, k, f);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    int get() {
        return tree[1].mx;
    }
};

struct Point {
    int x, y;
    bool c = false;
    bool operator < (const Point &p) const {
        return pii(x, y) < pii(p.x, p.y);
    }
};

struct Evt{
	int dx, dy, idx1, idx2;
    Evt(int dx, int dy, int idx1, int idx2) : dx(dx), dy(dy), idx1(idx1), idx2(idx2) {}
	bool operator < (const Evt &s)const{
		ll k = 1ll * dx * s.dy - 1ll * dy * s.dx;
		if(k != 0) return k > 0;
		return pii(idx1, idx2) < pii(s.idx1, s.idx2);
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
        cin >> a[i].x >> a[i].y;
        string s;
        cin >> s;
        if(s == "R") a[i].c = true;
    }

    if(n == 1) {
        if(a[0].c) cout << 1 << endl;
        else cout << 0 << endl;
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
    int idx = 0;
    SegmentTree ST;
    ST.Init(n);
    for(int i = 0; i < n; i++) {
        ST.Update(i, a[i].c);
    }

    int ans = ST.get();
    for(int i = 0; i < line.size(); i++) {
        int rx = pos[line[i].idx1], ry = pos[line[i].idx2];
        swap(a[rx], a[ry]);
        swap(pos[line[i].idx1], pos[line[i].idx2]);
        ST.Update(rx, a[rx].c);
        ST.Update(ry, a[ry].c);
        if(i + 1 < line.size() && ccw(line[i], line[i+1]) == 0) continue;
        ans = max(ans, ST.get());
    }
    cout << ans << endl;
}