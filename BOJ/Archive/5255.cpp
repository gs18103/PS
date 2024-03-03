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
};


inline bool equals(ld a, ld b) {return abs(a - b) < 1e-9;}

inline ld ccw(const line &a, const line &b) {
    return (a.t.x - a.s.x) * (b.t.y - b.s.y) - (a.t.y - a.s.y) * (b.t.x - b.s.x);
}
inline ld dist(const point &a, const point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool intersect(point &s1, point &e1, point &s2, point &e2, point &v) {
    ld vx1 = e1.x - s1.x, vy1 = e1.y - s1.y;
    ld vx2 = e2.x - s2.x, vy2 = e2.y - s2.y;
    ld det = vx2 * vy1 - vy2 * vx1;
    if(equals(det, 0)) return false;
    ld s = ((s2.x - s1.x) * (-vy2) + (s2.y - s1.y) * vx2) / det;
    v.x = s1.x + vx1 * s;
    v.y = s1.y + vy1 * s;
    return true;
}

bool bad(line& a, line& b, line& c) {
	point v;
	if(!intersect(a.s,a.t,b.s,b.t,v)) return false;
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
		if(!intersect(dq[i].s, dq[i].t, dq[j].s, dq[j].t, v)) continue;
		res.push_back(v);
	}
	return res;
}

void make_CH(vector <point> &p, vector <point> &CH) {
    sort(all(p), [&](const point &a, const point &b) {
        if(equals(a.x, b.x)) return a.y < b.y;
        return a.x < b.x;
    });
    sort(next(p.begin()), p.end(), [&p](const point &a, const point &b) {
        return ccw(line(p[0], a), line(p[0], b)) > 0;
    });
    for(auto i : p) {
        while(CH.size() >= 2 && ccw(line(CH[CH.size()-2], CH.back()), line(CH[CH.size()-2], i)) <= 0.0) CH.pop_back(); 
        CH.eb(i);
    }
}

ld farthest(vector <point> p) {
    if(p.empty()) return 0.0;
    vector <point> CH;
    make_CH(p, CH);
    CH.eb(CH[0]);

    int idx = 0;
    ld ret = 0.0;
    for(int i = 0; i + 1 < CH.size(); i++) {
        while(idx + 1 < CH.size() && ccw(line(CH[i], CH[i+1]), line(CH[idx], CH[idx+1])) >= 0.0) {
            ret = max(ret, dist(CH[i], CH[idx]));
            idx++;
        }
        ret = max(ret, dist(CH[i], CH[idx]));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed; cout.precision(3);

    int n;
    cin >> n;
    vector <point> p(n+1);
    for(int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    p[n] = p[0];

    ld lb = 0.0, ub = 2e7;
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
        if(farthest(HPI(ln)) >= 2 * r) lb = r;
        else ub = r;
    }
    cout << lb;
}