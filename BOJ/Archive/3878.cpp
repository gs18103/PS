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
    ll val = (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
    if(val > 0) return 1;
    if(val < 0) return -1;
    return 0;
}

bool Intersect(pll a, pll b, pll c, pll d) {
    ll ab = ccw(a, b, c) * ccw(a, b, d);
    ll cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        if(c <= b && a <= d) return true;
        else return false;
    }
    return (ab <= 0 && cd <= 0);
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

ll dot(pll a, pll b, pll c) {
    return (b.fi - a.fi) * (c.fi - a.fi) + (b.se - a.se) * (c.se - a.se);
}

bool is_in(vector <pll> &A, vector <pll> &CH) {
    if(CH.size() == 1) return false;
    for(auto i : A) {
        bool flag = (ccw(CH.back(), CH[0], i) > 0) || 
                    (ccw(CH.back(), CH[0], i) == 0 && dot(i, CH.back(), CH[0]) <= 0);
        for(int j = 0; j + 1 < CH.size(); j++) {
            flag &= (ccw(CH[j], CH[j+1], i) > 0) || 
                    (ccw(CH[j], CH[j+1], i) == 0 && dot(i, CH[j], CH[j+1]) <= 0);
        }
        if(flag) return true;
    }
    return false;
}

bool is_cross(vector <pll> &CHA, vector <pll> &CHB) {
    if(CHA.size() == 1 || CHB.size() == 1) return false;
    int sa = CHA.size(), sb = CHB.size();
    for(int i = 0; i < sa; i++) {
        for(int j = 0; j < sb; j++) {
            if(Intersect(CHA[i], CHA[(i+1)%sa], CHB[j], CHB[(j+1)%sb])) return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector <pll> A(n), B(m);
    for(int i = 0; i < n; i++) {
        cin >> A[i].fi >> A[i].se;
    }
    for(int i = 0; i < m; i++) {
        cin >> B[i].fi >> B[i].se;
    }
    vector <pll> CHA, CHB;
    make_convex_hull(A, CHA);
    make_convex_hull(B, CHB);
    if(is_in(A, CHB) || is_in(B, CHA) || is_cross(CHA, CHB)) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout.precision(30);
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}