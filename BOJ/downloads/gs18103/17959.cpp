#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define eb emplace_back
#define em emplace

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    ll lc, pc, lm, pm, t, d;
    cin >> n >> k;
    cin >> lc >> pc >> lm >> pm;
    cin >> t >> d;
    vector <ll> a(n+1), sm(n+1), sc(n+1), s(n+1), som(n+1), soc(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin()+1, a.end());
    for(int i = 1; i <= n; i++) {
        sm[i] = sm[i-1] + max(0LL, lm - a[i]);
        sc[i] = sc[i-1] + max(0LL, lc - a[i]);
        som[i] = som[i-1] + min(d, max(0LL, a[i] - lm));
        soc[i] = soc[i-1] + min(d, max(0LL, a[i] - lc));
        s[i] = s[i-1] + min(d, a[i] - 1);
    }

    ll ans = LINF;
    int i;
    for(i = 0; i * k <= n; i++) {
        if(i > 0 && a[n-i+1] + d < lc) continue;
        if(i * k < n && a[i*(k-1)+1] + d < lm) continue;

        ll x = sc[n] - sc[n-i] + sm[n-i] - sm[i*(k-1)];
        ll mx = soc[n] - soc[n-i] + som[n-i] - som[i*(k-1)] + s[i*(k-1)];
        if(x > mx) continue;

        ll tans = pc * i + pm * (n - i * k) + t * x;
        ans = min(ans, tans);
    }
    if(a[n-i+1] + d >= lc) {
        ll x = sc[n] - sc[n-i];
        ll mx = soc[n] - soc[n-i] + s[n-i];
        ll tans = pc * i + t * x;
        if(x <= mx) ans = min(ans, tans);
    }
    if(ans == LINF) cout << "-1\n";
    else cout << ans << endl;
}