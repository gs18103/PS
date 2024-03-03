#include  <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; ll X, F;
    cin >> n >> X >> F;
    vector <ll> x(n+1), a(n+1), p(n+1);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> p[i] >> a[i];
    }
    x[n] = X;

    set <pll> s;
    s.em(p[0], a[0]);
    ll ans = 0;
    ll cur = x[0];
    ll sum = a[0];
    for(int i = 1; i <= n; i++) {
        while(!s.empty()) {
            ll tp = s.begin()->fi, ta = s.begin()->se;
            s.erase(s.begin());
            if(cur + ta >= x[i]) {
                ans += (x[i] - cur) * tp;
                ta -= x[i] - cur;
                sum -= x[i] - cur;
                if(ta) s.em(tp, ta);
                cur = x[i];
                break;
            }
            cur += ta;
            ans += tp * ta;
            sum -= ta;
        }
        if(cur < x[i]) {
            cout << "-1\n";
            return 0;
        }

        s.em(p[i], a[i]);
        sum += a[i];
        while(!s.empty() && sum > F) {
            ll tp = s.rbegin()->fi, ta = s.rbegin()->se;
            s.erase(*s.rbegin());
            if(sum - ta <= F) {
                ta -= sum - F;
                sum = F;
                if(ta) s.em(tp, ta);
                break;
            }
            sum -= ta;
        }
    }
    cout << ans << endl;
}