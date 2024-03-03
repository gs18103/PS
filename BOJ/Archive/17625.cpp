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

const int MAX = 2020;
const int INF = 1e9;
const ll LINF = 9e18;

struct Evt {
    int dx, dy, idx1, idx2;
    Evt(int dx, int dy, int idx1, int idx2) : dx(dx), dy(dy), idx1(idx1), idx2(idx2) {}
    bool operator < (const Evt &p) const {
        ll c = (ll)dx * p.dy - (ll)dy * p.dx;
        if(c == 0) return pii(idx1, idx2) < pii(p.idx1, p.idx2);
        return c > 0;
    }
};

ll ccw(Evt a, Evt b) {
    return (ll)a.dx * b.dy - (ll)a.dy * b.dx;
}

struct Point {
    int x, y;
    bool operator < (const Point &p) const {
        return pii(x, y) < pii(p.x, p.y);
    }
};

double dist(Point a, Point b) {
    return sqrt((ll)(a.x - b.x) * (a.x - b.x) + (ll)(a.y - b.y) * (a.y - b.y));
}

double ldist(Point a, Point b1, Point b2) {
    return abs((ll)(a.x - b1.x) * (b2.y - b1.y) - (ll)(a.y - b1.y) * (b2.x - b1.x)) / dist(b1, b2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;

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
            if(a[j].y > a[i].y) line.eb(a[j].y - a[i].y, a[i].x - a[j].x, j, i);
            else if(a[j].y == a[i].y && a[i].x > a[j].x) line.eb(a[j].y - a[i].y, a[i].x - a[j].x, j, i);
            else line.eb(a[i].y - a[j].y, a[j].x - a[i].x, j, i);
        }
    }
    sort(all(line));

    double ans = 0.0;
    for(int i = 0; i < line.size(); i++) {
        int rx = pos[line[i].idx1], ry = pos[line[i].idx2];
        if(line[i].idx1 < line[i].idx2) {
            swap(a[rx], a[ry]);
            swap(pos[line[i].idx1], pos[line[i].idx2]);
            if(rx > ry) swap(rx, ry);
            if(rx > 0) ans = max(ans, ldist(a[rx-1], a[rx], a[rx+1]));
            if(ry < n - 1) ans = max(ans, ldist(a[ry+1], a[ry], a[ry-1]));
        }
        else {
            if(rx > ry) swap(rx, ry);
            if(ry - rx == 1) ans = max(ans, dist(a[rx], a[ry]));
        }
    }
    cout << ans / 2 << endl;
}