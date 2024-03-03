#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

struct point {
    ld x, y;
    point() {}
    point(ld _x, ld _y) : x(_x), y(_y) {}
};

struct line {
    point s, t;
    line() {}
    line(point _s, point _t) : s(_s), t(_t) {}
    ld dx() {return t.x - s.x;}
    ld dy() {return t.y - s.y;}
};

inline bool equals(ld a, ld b) {return abs(a - b) < 1e-9;}
inline ld ccw(line a, line b) {
    return (a.t.x - a.s.x) * (b.t.y - b.s.y) - (a.t.y - a.s.y) * (b.t.x - b.s.x);
}

bool intersect(line &a, line &b, point &v) {
    ld dx1 = a.dx(), dy1 = a.dy();
    ld dx2 = b.dx(), dy2 = b.dy();
    if(equals(ccw(a, b), 0)) return false;
    ld s = ccw(line(point(0, 0), point(dx2, dy2)), line(a.s, b.s)) / ccw(b, a);
    v.x = a.s.x + dx1 * s;
    v.y = a.s.y + dy1 * s;
    return true;
}

bool bad(line& a, line& b, line& c) {
	point v;
	if(!intersect(a, b, v)) return false;
	ld crs = ccw(c, line(c.s, v));
	return crs < 0 || equals(crs, 0);
}

vector <point> HPI(vector<line>& ln) {
	auto lsgn = [&](const line& a) {
		if(a.s.y == a.t.y) return a.s.x > a.t.x;
		return a.s.y > a.t.y;
	};
	sort(all(ln), [&](const line& a, const line& b) {
		if(lsgn(a) != lsgn(b)) return lsgn(a) < lsgn(b);
		return ccw(a, b) > 0;
	});

	deque <line> dq;
	for(int i = 0; i < ln.size(); i++) {
		while(dq.size() >= 2 && bad(dq[dq.size()-2], dq.back(), ln[i])) dq.pop_back();
		while(dq.size() >= 2 && bad(dq[0], dq[1], ln[i])) dq.pop_front();
		if(dq.size() < 2 || !bad(dq.back(), ln[i], dq[0])) dq.push_back(ln[i]);
	}
	vector<point> res;
	if(dq.size() >= 3) for(int i = 0; i < dq.size(); i++) {
		int j = (i + 1) % dq.size();
		point v;
		if(!intersect(dq[i], dq[j], v)) continue;
		res.push_back(v);
	}
	return res;
}

void solve(int n) {
    vector <point> p(n+1);
    for(int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    p[n] = p[0];

    ld lb = 0.0, ub = 10000.0;
    vector <line> ln(n);
    while(!equals(lb, ub)) {
        ld r = (lb + ub) / 2;
        for(int i = 0; i < n; i++) {
            ln[i] = line(p[i], p[i+1]);
            ld dx = p[i+1].x - p[i].x, dy = p[i+1].y - p[i].y;
            ld len = sqrt(dx * dx + dy * dy);
            dx *= r / len, dy *= r / len;
            ln[i].s.x -= dy, ln[i].t.x -= dy;
            ln[i].s.y += dx, ln[i].t.y += dx;
        }
        if(HPI(ln).empty()) ub = r;
        else lb = r;
    }
    cout << lb << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed; cout.precision(6);
    int n;
    cin >> n;
    while(n) {
        solve(n);
        cin >> n;
    }
}