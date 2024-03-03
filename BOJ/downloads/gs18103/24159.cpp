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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

int mypow(int a, int b, int p) {
    int r = 1;
    while(b) {
        if(b & 1) r = r * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return r;
}

int pw[MAX], cnt[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int p, n;
    cin >> p >> n;
    for(int i = 0; i < p; i++) {
        pw[i] = mypow(i, n, p);
        cnt[pw[i]]++;
    }
    int zero = 0, one = 0, q = 0;
    for(int i = 0; i < p; i++) {
        zero += cnt[0] * cnt[i] * cnt[(p-i)%p];
        one += cnt[1] * cnt[i] * cnt[(p-i+1)%p];
        if(i && cnt[i]) q++;
    }
    cout << zero + one * q;
}