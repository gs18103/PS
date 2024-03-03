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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int w, h, k, t;
    cin >> w >> h >> k >> t;
    ll ans = 1;
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        ll tval = 1;
        tval *= min(w, x + t) - max(1, x - t) + 1;
        tval *= min(h, y + t) - max(1, y - t) + 1;
        tval %= mod;
        ans = (ans * tval) % mod;
    }
    cout << ans << '\n';
}