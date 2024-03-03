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
typedef complex <double> cpx;

const int MAX = 1010101;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const double PI = 3.141592653589793238462643383279;

bool chk[MAX];

void FFT(vector<cpx> &a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cpx wlen(cos(ang), sin(ang));

        for (int i = 0; i < n; i += len) {
            cpx w(1);
            for (int j = 0; j < len / 2; j++) {
                cpx u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if(invert) {
        for(int i = 0; i < n; i++) {
            a[i] /= cpx(n, 0);
            a[i] = cpx(round(a[i].real()), round(a[i].imag()));
        }
    }
}

vector <cpx> multiply(vector <cpx> a, vector <cpx> b) {
    int n = 1;
    while(n < a.size() || n < b.size()) {
        n <<= 1;
    }
    n <<= 1;
    a.resize(n);
    b.resize(n);
    vector <cpx> c(n);

    FFT(a, 0);
    FFT(b, 0);

    for(int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }

    FFT(c, 1);
    return c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    vector <cpx> a(1 << 19), b(1 << 19), c(1 << 20);
    vector <int> p;
    for(int i = 2; i <= 1000000; i++) {
        if(!chk[i]) {
            p.eb(i);
            if(i & 1) {
                a[i/2] = 1;
            }
            if(i <= 500000) b[i] = 1;
        }
        for(auto j : p) {
            if(i * j > 1000000) break;
            chk[i * j] = true;
            if(i % j == 0) break;
        }
    }

    c = multiply(a, b);

    int q;
    cin >> q;
    while(q--) {
        int u;
        cin >> u;
        cout << (int)(c[u/2].real()) << '\n';
    }
}