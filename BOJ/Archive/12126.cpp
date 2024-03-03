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

const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> v(n);
    vector <int> p(m);
    for(int i = 0; i < n; i++) {
        v[i].resize(m);
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for(int i= 0; i < m; i++) {
        p[i] = i;
    }

    int f = 1;
    int ans = -INF;
    for(int i = 2; i <= m; i++) f *= i;

    for(int t = 0; t < f; t++) {
        int tans = 0;
        for(int i = 0; i < n; i++) {
            int c = 0, val = 0;
            for(int j = 0; j < m; j++) {
                c += v[i][p[j]];
                val = max(val, c);
            }
            tans += val;
        }
        ans = max(ans, tans);
        next_permutation(all(p));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}