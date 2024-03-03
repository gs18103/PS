#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int INF = 1 << 30;
const ll LINF = 1LL << 62;
const int MAX = 101010;
const ll mod = 1e9+7;

ll a[3*MAX], c[3*MAX], sum[3*MAX], ssum[3*MAX];
ll fuck[3*MAX], shit[3*MAX];
pll X[3*MAX];

ll mul(ll x, ll y) {
    return (x * y) % mod;
}

ll add(ll x, ll y) {
    return ((x + y) % mod + mod) % mod;
}

ll inv(ll n) {
   ll r=1;
   for (int i=30; i>=0; i--) {
      r=r*r%mod;
      if ((1ll<<i)&(mod-2)) r=r*n%mod;
   }
   return r;
}

ll val(ll x, ll y) {
    return mul(x, inv(y));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        sum[i] = (sum[i-1] + a[i]) % mod;
    }
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for(int i = 1; i < n; i++) {
        X[i] = {mul(2 * a[i], c[i]), sum[i]};
        ssum[i] = ssum[i-1] + val(X[i].fi, X[i].se);
    }
    fuck[1] = mul(2 * a[1], c[1]);
    for(int i = 2; i < n; i++) {
        fuck[i] = add(mul(fuck[i-1], add(1, val(a[i], sum[i]))), 
                mul(mul(2 * a[i], add(2, -val(a[i], sum[i]))), c[i]));
    }

    while(q--) {
        int u, v;
        cin >> u >> v;
        if(u == v) {
            cout << "0\n";
            continue;
        }
        if(u < v) swap(u, v);
        cout << add(add(add(ssum[u-1], -ssum[v]), add(c[u], c[v])), val(fuck[v-1], sum[v])) << '\n';
    }
}