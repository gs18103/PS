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
const int INF = 1e9;
const ll LINF = 9e18;

ll ccw(pll a, pll b, pll c) {
    return (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
}

ll ccw2(pll a, pll b, pll c, pll d) {
    return (b.fi - a.fi) * (d.se - c.se) - (b.se - a.se) * (d.fi - c.fi);
}

void make_convex_hull(vector <pll> &A, vector <pll> &CH) {
    sort(all(A), [&](pll a, pll b) {
        return a < b;
    });
    sort(next(A.begin()), A.end(), [&A](pll a, pll b) {
        return ccw(A[0], a, b) > 0;
    });
    for(auto i : A) {
        while(CH.size() >= 2 && ccw(CH[CH.size()-2], CH[CH.size()-1], i) <= 0) CH.pop_back();
        CH.eb(i);
    }
}

double dist(pll a, pll b) {
    return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

double ldist(pll a, pll b1, pll b2) {
    return abs((ll)(a.fi - b1.fi) * (b2.se - b1.se) - (ll)(a.se - b1.se) * (b2.fi - b1.fi)) / dist(b1, b2);
}

double farthest(vector <pll> CH) {
    int idx = 0;
    double ret = 0.0;
    for(int i = 0; i < CH.size(); i++) {
        while(idx + 1 < CH.size() && ccw2(CH[i], CH[i+1], CH[idx], CH[idx+1]) >= 0) {
            ret = max(ret, dist(CH[i], CH[idx]));
            idx++;
        }
        ret = max(ret, dist(CH[i], CH[idx]));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout.precision(9); cout << fixed;
    int n;
    cin >> n;
    vector <pll> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i].fi >> A[i].se;
    }
    vector <pll> CH;
    make_convex_hull(A, CH);
    cout << farthest(CH) << endl;
}