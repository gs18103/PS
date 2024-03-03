#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

ll lcm(ll x, ll y) {
    ll g = __gcd(x, y);
    return g == 0 ? 0 : (x / g) * y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector <ll> a(5);
    for(int i = 0; i < 5; i++) {
        cin >> a[i];
    }

    ll ans = LINF;
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            for(int k = j + 1; k < 5; k++) {
                ans = min(ans, lcm(lcm(a[i], a[j]), a[k]));
            }
        }
    }
    cout << ans;
}