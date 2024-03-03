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

void solve() {
    ll n, k;
    cin >> n >> k;
    int lb = 0, ub = 5000;
    while(lb < ub) {
        int m = lb + ub + 1 >> 1;
        if(k * m * (m + 1) / 2 < n) lb = m;
        else ub = m - 1;
    }
    if(lb & 1) cout << k * (lb + 1) / 2 - (n - 1 - k * lb * (lb + 1) / 2) << " L\n";
    else cout << - k * (lb / 2) + n - 1 - k * lb * (lb + 1) / 2 << " R\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}