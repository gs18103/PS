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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <ll> p, chk(m+1);
    for(int i = 2; i <= m; i++) {
        if(!chk[i]) p.eb(i);
        for(auto j : p) {
            if(i * j > m) break;
            chk[i*j] = true;
            if(i % j == 0) break;
        }
    }
    for(auto i : p) {
        if(i < n) continue;
        cout << i << '\n';
    }
}