#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <int, ll> pil;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector <pll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }
    sort(all(v));
    ll s = 0, rs = 0;
    for(int i = 0; i < n; i++) {
        s += v[i].se - v[i].fi;
        rs += v[i].se + v[i].fi;
    }
    ll ans = min(s - v[n-1].se + v[n-1].fi + v[n-2].fi * (n - 1), 
                     rs - v[0].se - v[0].fi - v[1].fi * (n - 1));
    for(int i = 0; i < n; i++) {
        if(i + 1 < n) ans = min(ans, s - v[i].se + v[i].fi + v[n-1].fi * (n - 1));
        if(i > 0) ans = min(ans, rs - v[i].se - v[i].fi - v[0].fi * (n - 1));
    }
    cout << ans << '\n';
}