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

class UnionFindTree {
public:
    vector <int> p;
    int cnt;
    UnionFindTree(int n) {
        cnt = n;
        p.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        cnt--;
        if(x > y) swap(x, y);
        p[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <Point> a(n);
    vector <int> pos(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
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


    ll ans = 0;
    set <int> st;
    UnionFindTree UFT(n);
    for(int i = 0; i < line.size(); i++) {
        int rx = pos[line[i].idx1], ry = pos[line[i].idx2];
        swap(a[rx], a[ry]);
        swap(pos[line[i].idx1], pos[line[i].idx2]);
        st.em(line[i].idx1);
        st.em(line[i].idx2);
        UFT.uni(line[i].idx1, line[i].idx2);
        if(i + 1 < line.size() && ccw(line[i], line[i+1]) == 0) continue;
        ans += n - UFT.cnt;
        for(auto i : st) UFT.p[i] = i;
        UFT.cnt = n;
        st.clear();
    }
    cout << (2 * ans) % (1000000007LL) << endl;
}