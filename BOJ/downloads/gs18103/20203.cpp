#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

struct UnionFindTree {
    vector <int> p, val;

    void Init(int n) {
        p.resize(n+1);
        val.resize(n+1);
        for(int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }
    
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    int get(int x) {
        return val[find(x)];
    }
    
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(val[x] < val[y]) swap(x, y);
        p[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    UnionFindTree UFT;
    UFT.Init(n);
    for(int i = 1; i <= n; i++) {
        cin >> UFT.val[i];
    }

    vector <pii> E;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        E.eb(u, v);
    }
    sort(all(E), [&UFT](pii a, pii b) {
        return max(UFT.val[a.fi], UFT.val[a.se]) < max(UFT.val[b.fi], UFT.val[b.se]);
    });
    ll ans = 0;
    for(auto i : E) {
        int x = i.fi, y = i.se;
        ans += UFT.get(x) + UFT.get(y);
        UFT.uni(x, y);
    }
    cout << ans;
}