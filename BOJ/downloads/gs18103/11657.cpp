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

const int MAX = 505;
const int INF = 1e9;
const ll LINF = 1e18;

ll d[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <pair <pii, ll> > E(m);
    for(int i = 0; i < m; i++) {
        cin >> E[i].fi.fi >> E[i].fi.se >> E[i].se;
    }
    for(int i = 2; i <= n; i++) {
        d[i] = LINF;
    }
    for(int i = 1; i <= n; i++) {
        for(auto j : E) {
            if(d[j.fi.fi] == LINF) continue;
            d[j.fi.se] = min(d[j.fi.fi] + j.se, d[j.fi.se]);
        }
    }
    for(auto j : E) {
        if(d[j.fi.fi] == LINF) continue;
        if(d[j.fi.se] > d[j.fi.fi] + j.se) return cout << -1, 0;
    }
    for(int i = 2; i <= n; i++) {
        if(d[i] == LINF) cout << "-1\n";
        else cout << d[i] << '\n';
    }
}