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
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        int x1, y1, x2, y2, r1, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int rmx = (r1 + r2) * (r1 + r2), rmn = (r1 - r2) * (r1 - r2);
        if(d == 0) {
            if(rmn == 0) cout << "-1\n";
            else cout << "0\n";
        }
        else {
            if(d > rmx || d < rmn) cout << "0\n";
            if(d == rmx || d == rmn) cout << "1\n";
            if(d < rmx && d > rmn) cout << "2\n";
        }
    }
}