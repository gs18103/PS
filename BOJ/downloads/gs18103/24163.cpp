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

int p[MAX], ans[MAX], eulerphi[MAX];
bool chk[MAX], pchk[MAX];
vector <vector <int> > C[MAX];

ll mypow(ll a, ll b, ll m) {
    ll r = 1;
    while(b) {
        if(b & 1) r = (r * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, K;
    cin >> n >> K;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        eulerphi[i] = i;
    }
    for(int i = 2; i <= n; i++) {
        if(pchk[i]) continue;
        for(int j = i; j <= n; j += i) {
            eulerphi[j] -= eulerphi[j] / i;
            pchk[j] = true;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(chk[i]) continue;
        vector <int> v = {i};
        int x = p[i];
        while(x != i) {
            v.eb(x);
            x = p[x];
        }
        for(int j : v) chk[j] = true;
        C[v.size()].eb(v);
    }
    for(int i = 1; i <= n; i++) {
        if(C[i].empty()) continue;
        int m = C[i].size();
        if(__gcd(K / __gcd(K, m), i) != 1) return !(cout << 0);
        int g = __gcd(K, m), x = K / __gcd(K, m);
        int shift = mypow(x, eulerphi[i] - 1, i);
        for(int j = 0; j < C[i].size(); j += g) {
            vector <int> v;
            for(int k = 0; k < i; k++) {
                for(int l = j; l < j + g; l++) {
                    v.eb(C[i][l][k]);
                }
            }
            for(int k = 0; k < v.size(); k++) {
                ans[v[k]] = v[(k + shift)%v.size()];
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
}