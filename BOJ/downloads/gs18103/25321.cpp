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

ll fact[MAX], finv[MAX];
int cnt[MAX];

ll inv(ll a, ll b = mod - 2) {
    ll r = 1;
    while(b) {
        if(b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

ll C(int n) {
    return (((((fact[2*n] * finv[n]) % mod) * finv[n]) % mod) * inv(n+1)) % mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    string s;
    cin >> s;
    fact[0] = 1;
    for(int i = 1; i <= s.size(); i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    finv[s.size()] = inv(fact[s.size()]);
    for(int i = s.size(); i > 0; i--) {
        finv[i-1] = (finv[i] * i) % mod;
    }
    int num = 0;
    ll ans = 1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '?') num++;
        if(s[i] == ':') {
            ans *= C(cnt[num]);
            ans %= mod;
            cnt[num] = 0;
            num--;
            cnt[num]++;
        }
    }
    ans *= C(cnt[0]);
    ans %= mod;
    cout << ans;
}