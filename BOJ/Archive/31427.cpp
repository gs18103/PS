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
typedef pair <int, ll> pil;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

struct DSU {
    vector <int> p;
    DSU(int n) {
        p.resize(n+1);
        for(int i = 1; i <= n; i++) p[i] = i;
    }

    void clear() {
        for(int i = 1; i < p.size(); i++) p[i] = i;
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
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
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector <vector <pii>> E(5);
    for(int i = 0; i < m; i++) {
        int u, v; string t;
        cin >> u >> v >> t;
        E[t[0]-'A'].eb(u, v);
    }
    vector <int> v = {0, 1, 2, 3, 4};
    vector <vector <int>> cnt(120);
    vector <vector <int>> perm(120);

    DSU uft(n);
    for(int i = 0; i < 120; i++) {
        cnt[i].resize(5);
        for(int j = 0; j < 5; j++) {
            for(pii &x : E[v[j]]) {
                if(uft.uni(x.fi, x.se)) cnt[i][v[j]]++;
            }
        }
        uft.clear();
        perm[i] = v;
        next_permutation(all(v));
    }

    while(q--) {
        vector <pii> tv(5);
        for(int i = 0; i < 5; i++) {
            cin >> tv[i].fi; tv[i].se = i;
        }
        sort(all(tv));
        for(int i = 0; i < 120; i++) {
            bool flag = false;
            for(int j = 0; j < 5; j++) {
                if(tv[j].se != perm[i][j]) flag = true;
            }
            if(flag) continue;
            sort(all(tv), [](pii a, pii b) {return a.se < b.se;});
            ll ans = 0;
            for(int j = 0; j < 5; j++) ans += (ll)tv[j].fi * cnt[i][j];
            cout << ans << '\n';
        }
    }
}