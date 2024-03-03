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

int d(int x, int y, int xt, int yt) {
    return (x - xt) * (x - xt) + (y - yt) * (y - yt);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            ans += (d(x, y, x1, y1) < r * r) ^ (d(x, y, x2, y2) < r * r);
        }
        cout << ans << '\n';
    }
}