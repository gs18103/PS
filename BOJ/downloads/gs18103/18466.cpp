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
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    ll ans = 0;
    vector <bool> chk(k);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        ll v;
        int tcnt = 0;
        cin >> v;
        for(int j = 0; j < k; j++) {
            if(chk[j]) continue;
            if(v >> j & 1) {
                chk[j] = true;
                tcnt++;
            }
        }
        cnt += tcnt;
        ans = (ans + i * ((1LL << (k - cnt)) % mod) * (((1LL << tcnt) - 1) % mod)) % mod;
    }
    cout << ans;
}