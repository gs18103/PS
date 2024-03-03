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
typedef pair <int, int> pint;

const int MAX = 2020;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;
const int w = 3;

ll pw(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % mod;
        b >>= 1; a = a * a % mod;
    }
    return ret;
}

void ntt(vector <int> &a, int sz, bool inv = 0) {
    int ang = pw(w, (mod - 1) / sz); if(inv) ang = pw(ang, mod - 2);
    for (int ssz = sz / 2; ssz; ssz /= 2) {
        for (int i = 0; i < sz; i += ssz * 2) {
            ll wt = 1;
            for (int j = 0; j < ssz; ++j) {
                int &lft = a[i + j];
                int &rgh = a[i + j + ssz];
                int lftold = lft;
                lft = (lft + rgh) % mod;
                rgh = (lftold + (mod - rgh)) * wt % mod;
                wt = wt * ang % mod;
            }
        }
        ang = 1LL * ang * ang % mod;
    }
    if (inv) {
        ll invsz = pw(sz, mod - 2);
        for (int i = 0; i < sz; ++i) a[i] = a[i] * invsz % mod;
    }
    for (int j = 0, i = 1; i < sz; ++i) {
        int dg = sz / 2;
        for (; j & dg; dg >>= 1) j ^= dg;
        j ^= dg;
        if (i < j) swap(a[i], a[j]);
    }
}

void power_poly(vector <int> &a, int sz, int b) {
    if(b == 0) {a[0] = 1; return;}
    int n = 2;
    while(n < b * (sz - 1) + 1) n <<= 1;
    ntt(a, n);
    for(int i = 0; i < n; i++) a[i] = pw(a[i], b);
    ntt(a, n, 1);
}

vector <int> p1(1<<20), p2(1<<20);

void P(int n) {
    if(n == 0) {
        p1[0] = 1;
        return;
    }
    int sz = 2, m = n / 2; P(m);
    while(sz < n + 1) sz <<= 1;
    ntt(p1, sz), ntt(p2, sz);
    
    int W = pw(w, (mod - 1) / sz);
    int m11, m12, m22, r0, r1;
    for(int i = 0, x = 1; i < sz; i++, x = 1LL * x * W % mod) {
        m11 = 1LL * p1[i] * p1[i] % mod;
        m12 = 1LL * p1[i] * p2[i] % mod;
        m22 = 1LL * p2[i] * p2[i] % mod;

        r0 = (m11 + 1LL * x * m22) % mod;
        r1 = (2LL * m12 - 1LL * (x + 1) * m22) % mod;
        if (r1 < 0) r1 += mod;

        if (n % 2 == 1) {
            int rp1 = (1LL * (x + 1) * r0 + 1LL * x * r1) % mod;
            r1 = r0;
            r0 = rp1;
        }
        p1[i] = r0, p2[i] = r1;
    }
    ntt(p1, sz, 1), ntt(p2, sz, 1);
}

void f(int n) {
    P(n-1);
    for(int i = 0; i < n - 1; i++) {
        p1[i+1] = (p1[i+1] + p2[i]) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector <int> fact(n*m+1);
    fact[0] = 1;
    for(int i = 1; i <= n * m; i++) {
        fact[i] = 1LL * fact[i-1] * i % mod;
    }

    f(n);

    power_poly(p1, n, m);

    int ans = 0;
    for(int i = 0; i <= m * (n - 1); i++) {
        if(i & 1) ans += mod - (1LL * p1[i] * fact[n*m-i] % mod);
        else ans += 1LL * p1[i] * fact[n*m-i] % mod;
        ans %= mod;
    }
    cout << ans;
}