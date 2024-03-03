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

const int MAX = 202020;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

const double PI = acos(-1);
typedef complex <double> cpx;

void FFT(vector <cpx> &f, cpx w) {
    int n = f.size();
    if(n == 1) return;

    vector <cpx> even(n / 2), odd(n / 2);
    for(int i = 0; i < n; i++) {
        if(i & 1) odd[i / 2] = f[i];
        else even[i / 2] = f[i];
    }

    FFT(even, w * w);
    FFT(odd, w * w);

    cpx wp(1, 0);
    for(int i = 0; i < n / 2; i++) {
        f[i] = even[i] + wp * odd[i];
        f[i + n / 2] = even[i] - wp * odd[i];
        wp *= w;
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

    cpx w(cos(2*PI/n), sin(2*PI/n));

    FFT(a, w);
    FFT(b, w);
    for(int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }

    FFT(c, cpx(1, 0)/w);
    for(int i = 0; i < n; i++) {
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }
    return c;
}

vector <cpx> a, b, c;
ll ssa[MAX], ssb[MAX];

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    a.resize(n+1), b.resize(n+1), c.resize(n + 1);
    for(int i = 1; i <= q; i++) {
        int d, l;
        cin >> d >> l;
        if(d == 0) a[l] = cpx(1, 0);
        if(d == 60) b[l] = cpx(1, 0);
        if(d == 120) c[l] = cpx(1, 0);
    }

    a[0] = cpx(1, 0);
    b[0] = cpx(1, 0);
    c[n] = cpx(1, 0);
    ll ans = 0, sa = 0, sb = 0;
    vector <cpx> C = multiply(a, b);
    for(int i = 1; i <= n; i++) {
        ssa[i] = ssa[i-1];
        ssb[i] = ssb[i-1];
        if((int)a[i].real() == 1) {
            sa += ssb[min(i, n - i)] + 1;
            ssa[i]++;
        }
        if((int)b[i].real() == 1) {
            sb += ssa[min(i, n - i)] + 1;
            ssb[i]++;
        }
        ans += (ll)c[i].real() * (sa + sb + 1);
        ans -= (ll)C[i].real() * c[i].real();
    }
    cout << ans << endl;
}