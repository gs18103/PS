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

const int MAX = 505050;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; ll k;
    cin >> n >> k;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        ll u; cin >> u;
        sum += u;
    }
    ll ans = 1;
    for(ll i = n + k - sum; i > k - sum; i--) {
        ans = (ans * i) % mod;
    }
    cout << ans;
}