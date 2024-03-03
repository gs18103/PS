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
    int n;
    cin >> n;
    vector <int> t(n), v(n), chk(n);
    int x = 1;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        v[i] = i;
        if(i) x *= i;
    }
    if(n == 1) {
        cout << t[0] << '\n';
        return;
    }
    int ans = INF;
    for(int i = 0; i < x; i++) {
        int cnt = 1, tans = 0;
        for(int j = 0; j < n; j++) {
            chk[j] = 0;
        }
        auto p = next(v.begin());
        for(int j = 0; j < n; j++) {
            cnt += chk[j];
            for(int k = 0; k < cnt; k++) {
                if(j + t[*p] < n) chk[j+t[*p]]++;
                tans = max(tans, j + t[*p]);
                p++;
                if(p == v.end()) break;
            }
            if(p == v.end()) break;
        }
        ans = min(ans, tans);
        next_permutation(all(v));
    }
    cout << ans + t[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}