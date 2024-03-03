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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

struct UnionFindTree {
    vector <int> p;
    void Init(int n) {
        p.resize(n+1);
        for(int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(x > y) swap(x, y);
        p[y] = x;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <ll> C(n+1);
    vector <pair <ll, pii> > E(m);
    ll ans = 0, mn = LINF;
    for(int i = 1; i <= n; i++) {
        cin >> C[i];
        mn = min(mn, C[i]);
    }
    for(int i = 0; i < m; i++) {
        cin >> E[i].se.fi >> E[i].se.se >> E[i].fi;
        E[i].fi *= 2;
        E[i].fi += C[E[i].se.fi] + C[E[i].se.se];
    }
    sort(all(E));

    UnionFindTree UFT;
    UFT.Init(n);
    for(auto i : E) {
        if(UFT.uni(i.se.fi, i.se.se)) {
            ans += i.fi;
        }
    }
    cout << ans + mn;
}