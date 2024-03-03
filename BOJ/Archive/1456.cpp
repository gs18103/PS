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

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

bool chk[10101010];
vector <ll> p;

ll cal(ll x) {
    ll r = 0;
    for(auto i : p) {
        for(ll j = i; j <= x / i; j *= i) r++;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 2; i <= 10000000; i++) {
        if(!chk[i]) p.eb(i);
        for(int j : p) {
            if(i * j > 10000000) break;
            chk[i*j] = true;
            if(i % j == 0) break;
        }
    }

    cout << cal(m) - cal(n-1);
}