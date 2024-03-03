#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

typedef complex <long double> cpx;

const long double PI = 3.14159265358979323846264338;

void FFT(vector <cpx> &f, bool inv = 0){
    int n = f.size(), j = 0;
    vector <cpx> root(n >> 1);
    for(int i=1; i<n; i++){
        int bit = (n >> 1);
        while(j >= bit){
            j -= bit; bit >>= 1;
        }
        j += bit;
        if(i < j) swap(f[i], f[j]);
    }
    double ang = 2 * PI / n; if(inv) ang *= -1;
    for(int i=0; i<(n >> 1); i++) root[i] = cpx(cos(ang*i), sin(ang*i));
    for(int i=2; i<=n; i<<=1){
        int step = n / i;
        for(int j=0; j<n; j+=i){
            for(int k=0; k<(i >> 1); k++){
                cpx u = f[j | k], v = f[j | k | i >> 1] * root[step * k];
                f[j | k] = u + v;
                f[j | k | i >> 1] = u - v;
            }
        }
    }
    if(inv) for(int i=0; i<n; i++) f[i] /= n;
}

void multiply(vector <cpx> &a1, vector <cpx> &a2, vector <cpx> &b1, vector <cpx> &b2, vector <ll> &c) {
    int n = 2;
    while(n < a1.size() + b1.size()) {
        n <<= 1;
    }
    a1.resize(n);
    a2.resize(n);
    b1.resize(n);
    b2.resize(n);
    c.resize(n);
    vector <cpx> c1(n), c2(n), c3(n);

    FFT(a1, 0);
    FFT(b1, 0);
    FFT(a2, 0);
    FFT(b2, 0);

    for(int i = 0; i < n; i++) {
        c1[i] = a1[i] * b1[i];
        c2[i] = a1[i] * b2[i] + a2[i] * b1[i];
        c3[i] = a2[i] * b2[i];
    }

    FFT(c1, 1);
    FFT(c2, 1);
    FFT(c3, 1);
    for(int i = 0; i < n; i++) {
        c[i] = (llround(c1[i].real()) << 30) + (llround(c2[i].real()) << 15) + llround(c3[i].real());
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    n++, m++;
    vector <cpx> a1, a2, b1, b2;
    vector <ll> c;
    for(int i = 0; i < n; i++) {
        int u;
        cin >> u;
        a1.eb(cpx(u / (1 << 15), 0));
        a2.eb(cpx(u % (1 << 15), 0));
    }
    for(int i = 0; i < m; i++) {
        int u;
        cin >> u;
        b1.eb(cpx(u / (1 << 15), 0));
        b2.eb(cpx(u % (1 << 15), 0));
    }
    multiply(a1, a2, b1, b2, c);
    ll ans = 0;
    for(int i = 0; i < c.size(); i++) {
        ans ^= c[i];
    }
    cout << ans << endl;
}