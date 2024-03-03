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

const int MAX = 1010;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector <pii> A(n);
    map <int, vector <int> > X, Y;
    for(int i = 0; i < n; i++) {
        cin >> A[i].fi >> A[i].se;
        X[A[i].fi].eb(A[i].se);
        Y[A[i].se].eb(A[i].fi);
    }
    for(auto &i : X) {
        sort(all(i.se));
    }
    for(auto &i : Y) {
        sort(all(i.se));
    }
    vector <pii> ord;
    int x = 0, y = 0;
    while(1) {
        ord.eb(x, y);
        if(X[x][0] == y) {
            for(int i = 1; i < X[x].size(); i++) {
                ord.eb(x, X[x][i]);
                y = X[x][i];
            }
        }
        else {
            for(int i = X[x].size() - 2; i >= 0; i--) {
                ord.eb(x, X[x][i]);
                y = X[x][i];
            }
        }
        X.erase(x);
        auto it = upper_bound(all(Y[y]), x);
        if(it == Y[y].end()) break;
        x = *it;
    }
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int u;
        cin >> u;
        cout << ord[u-1].fi << ' ' << ord[u-1].se << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}