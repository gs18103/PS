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

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;

pair <ll, pll> X[MAX];

ll ccw(pll a, pll b, pll c) {
    return (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    ll xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> X[i].fi >> X[i].se.fi >> X[i].se.se;
    }
    X[n+1] = {xt, {yt, yt}};
    X[0] = {xs, {ys, ys}};

    vector <pll> ans;
    deque <pll> U, L;
    ans.eb(xs, ys);
    U.eb(xs, ys);
    L.eb(xs, ys);

    for(int i = 1; i <= n + 1; i++) {
        if(L.size() >= 2) {
            if(ccw(L[0], L[1], {X[i].fi, X[i].se.se}) <= 0) {
                while(L.size() >= 2 && ccw(L[0], L[1], {X[i].fi, X[i].se.se}) <= 0) {
                    ans.eb(L[1]);
                    L.pop_front();
                }
                U.clear();
                U.eb(ans.back());
            }
            else if(ccw(U[0], U[1], {X[i].fi, X[i].se.fi}) >= 0) {
                while(U.size() >= 2 && ccw(U[0], U[1], {X[i].fi, X[i].se.fi}) >= 0) {
                    ans.eb(U[1]);
                    U.pop_front();
                }
                L.clear();
                L.eb(ans.back());
            }
        }
        while(L.size() >= 2 && ccw(L[L.size()-2], L[L.size()-1], {X[i].fi, X[i].se.fi}) >= 0) {
            L.pop_back();
        }
        L.eb(X[i].fi, X[i].se.fi);
        while(U.size() >= 2 && ccw(U[U.size()-2], U[U.size()-1], {X[i].fi, X[i].se.se}) <= 0) {
            U.pop_back();
        }
        U.eb(X[i].fi, X[i].se.se);
    }
    for(auto i : ans) {
        cout << i.fi << ' ' << i.se << '\n';
    }
    cout << xt << ' ' << yt;
}