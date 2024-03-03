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
typedef pair <int, ll> pil;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;


struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (const Point &p) const {
        return pii(x, y) < pii(p.x, p.y);
    }

    Point operator - (const Point &p) {
        return Point(x - p.x, y - p.y);
    }
};

ll ccw(Point a, Point b) {
    return (ll)a.x * b.y - (ll)a.y * b.x;
}

struct EVT {
    int x, y, idx;
    EVT(int _x, int _y, int _idx) : x(_x), y(_y), idx(_idx) {}
    bool operator < (const EVT &X) const {
        return ccw(Point(x, y), Point(X.x, X.y)) > 0;
    }
};

double dist(Point a, Point b) {
    return sqrt((ll)(a.x - b.x) * (a.x - b.x) + (ll)(a.y - b.y) * (a.y - b.y));
}

double ldist(Point a, Point b1, Point b2) {
    return abs((ll)(a.x - b1.x) * (b2.y - b1.y) - (ll)(a.y - b1.y) * (b2.x - b1.x)) / dist(b1, b2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout << fixed; cout.precision(18);

    int n;
    cin >> n;
    vector <Point> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    sort(all(v));
    multiset <EVT> st;
    for(int i = 1; i < n; i++) {
        st.em(v[i-1].x - v[i].x, v[i-1].y - v[i].y, i);
    }

    Point pre = Point(-1, 2*INF + 1);
    double ans = 1e18;
    while(!st.empty()) {
        EVT cur = *st.begin();
        st.erase(st.begin());
        int i = cur.idx;
        if(i > 1) {
            Point temp = v[i-2] < v[i-1] ? v[i-2] - v[i-1] : v[i-1] - v[i-2];
            if(st.find(EVT(temp.x, temp.y, i - 1)) != st.end()) {
                st.erase(st.find(EVT(temp.x, temp.y, i - 1)));
            }
        }
        if(i + 1 < n) {
            Point temp = v[i] < v[i+1] ? v[i] - v[i+1] : v[i+1] - v[i];
            if(st.find(EVT(temp.x, temp.y, i + 1)) != st.end()) {
                st.erase(st.find(EVT(temp.x, temp.y, i + 1)));
            }
        }
        swap(v[i], v[i-1]);
        if(i > 1) {
            if(ccw(v[i-2]- v[i], v[i-1] - v[i]) == 0) {
                cout << "0\n";
                return 0;
            }
            ans = min(ans, ldist(v[i-2], v[i-1], v[i]));

            Point temp = v[i-2] < v[i-1] ? v[i-2] - v[i-1] : v[i-1] - v[i-2];
            if(ccw(pre, temp) >= 0) st.em(temp.x, temp.y, i - 1);
        }
        if(i + 1 < n) {
            if(ccw(v[i+1] - v[i], v[i-1] - v[i]) == 0) {
                cout << "0\n";
                return 0;
            }
            ans = min(ans, ldist(v[i+1], v[i], v[i-1]));

            Point temp = v[i] < v[i+1] ? v[i] - v[i+1] : v[i+1] - v[i];
            if(ccw(pre, temp) >= 0) st.em(temp.x, temp.y, i + 1);
        }
        pre = Point(cur.x, cur.y);
    }
    cout << ans << endl;
}