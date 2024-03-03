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

pii fibo[33];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int d, k;
    cin >> d >> k;
    fibo[1] = {1, 0}, fibo[2] = {0, 1};
    for(int i = 3; i <= d; i++) {
        fibo[i] = {fibo[i-1].fi + fibo[i-2].fi, fibo[i-1].se + fibo[i-2].se};
    }

    for(int i = 1; i <= k; i++) {
        if((k - i * fibo[d].fi) % fibo[d].se == 0) {
            cout << i << '\n' << (k - i * fibo[d].fi) / fibo[d].se;
            return 0;
        }
    }
}