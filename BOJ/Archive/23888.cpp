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

    ll a, d;
    cin >> a >> d;
    ll g = __gcd(a, d);
    int q;
    cin >> q;
    while(q--) {
        int t; ll l, r;
        cin >> t >> l >> r;
        if(t == 1) {
            cout << a * (r - l + 1) + d * (r * (r - 1) / 2 - (l - 2) * (l - 1) / 2) << '\n';
        }
        if(t == 2) {
            if(l == r) cout << a + (l - 1) * d << '\n';
            else cout << g << '\n';
        }
    }
}