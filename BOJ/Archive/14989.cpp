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
const ll mod = 1e9+7;

ll dp[303][303];
bool chk[303][303];

ll f(int h, int w) {
    if(w == 1) return h >= 1;
    if(h == 0) return 0;
    if(chk[h][w]) return dp[h][w];
    chk[h][w] = true;
    for(int i = 1; i < w; i++) {
        dp[h][w] += (f(h, w - i) * f(h - 1, i)) % mod;
        dp[h][w] %= mod;
    }
    return dp[h][w];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    cout << (f(h, w) - f(h - 1, w) + mod) % mod;
}