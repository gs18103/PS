#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 4040404;
const int INF = 1e9;
const ll LINF = 1e18;

struct UFT{
    vector <int> p;
    int sz;
    UFT(int n) {
        sz = n;
        p.resize(n+1);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if(x > y) swap(x, y);
        p[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector <pair <int, pii> > E;
    for(int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        E.eb(c, pii(u, v));
    }
    sort(all(E));
    UFT T(n);
    
    ll ans = 0;
    int mx = 0;
    for(auto i : E) {
        int x = i.se.fi, y = i.se.se;
        if(T.find(x) == T.find(y)) continue;
        T.uni(x, y);
        ans += i.fi;
        mx = i.fi;
    }
    cout << ans - mx;
}
