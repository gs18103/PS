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

pair <int, pll> p[MAX];
int x[MAX], s[MAX], t[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        cin >> p[i].fi >> p[i].se.fi >> p[i].se.se;
    }
    sort(p+1, p+k+1);
    for(int i = 1; i <= k; i++) {
        x[i] = p[i].fi;
        t[i] = p[i].se.fi;
        s[i] = p[i].se.se;
    }

    ll ans = 0;
    for(int i = 1; i <= k; i++) {
        ans += x[i] - x[i-1];
        if(ans < s[i]) ans = s[i];
        else if((ans - s[i]) % (2 * t[i]) >= t[i]) ans += 2 * t[i] - ((ans - s[i]) % (2 * t[i]));
    }
    ans += n - x[k];
    cout << ans;
}