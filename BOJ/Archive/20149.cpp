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
    ll val = a.fi * b.se + b.fi * c.se + c.fi * a.se - a.se * b.fi - b.se * c.fi - c.se * a.fi;
    if(val > 0) return 1;
    if(val < 0) return -1;
    return 0;
}

void get_point(pll a, pll b, pll c, pll d) {
    ll tmp = (a.fi - b.fi) * (c.se - d.se) - (a.se - b.se) * (c.fi - d.fi);
    ll c1 = (a.fi * b.se - a.se * b.fi), c2 = (c.fi * d.se - c.se * d.fi);
    if(tmp == 0) {
        if(b == c) cout << b.fi << ' ' << b.se << endl;
        else if(a == d) cout << a.fi << ' ' << a.se << endl;
    }
    else cout << (double)(c1 * (c.fi - d.fi) - c2 * (a.fi - b.fi)) / tmp << ' ' << (double)(c1 * (c.se - d.se) - c2 * (a.se - b.se)) / tmp << endl;

}

void Intersect(pll a, pll b, pll c, pll d) {
    ll ab = ccw(a, b, c) * ccw(a, b, d);
    ll cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        if(c <= b && a <= d) {
            cout << 1 << endl;
            get_point(a, b, c, d);
        }
        else {
            cout << 0 << endl;
        }
        return;
    }
    if(ab <= 0 && cd <= 0) {
        cout << 1 << endl;
        get_point(a, b, c, d);
    }
    else {
        cout << 0 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(9);

    ll x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    Intersect({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4});
}