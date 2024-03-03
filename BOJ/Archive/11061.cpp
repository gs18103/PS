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

class UnionFindTree {
    vector <int> p, sz, cnt;
public:
    void Init(int n) {
        p.resize(n+1);
        sz.resize(n+1);
        cnt.resize(n+1);
        for(int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
    }
    int find(int x) {
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) {
            cnt[x]++;
            return;
        }
        if(x > y) swap(x, y);
        sz[x] += sz[y];
        cnt[x] += cnt[y];
        cnt[x]++;
        p[y] = x;
    }
    bool is_complete(int x) {
        x = find(x);
        return (sz[x] * (sz[x] - 1) / 2) == cnt[x];
    }
};

void solve() {
    int n;
    cin >> n;
    vector <pair <int, pii> > h;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int t;
            cin >> t;
            h.eb(t, make_pair(i, j));
        }
    }
    sort(all(h));
    int ans = 0;
    UnionFindTree UFT;
    UFT.Init(n);
    vector <int> temp;
    map <int, bool> chk;
    for(int i = 0; i < h.size(); i++) {
        int x = h[i].se.fi, y = h[i].se.se;
        UFT.uni(x, y);
        temp.eb(x);
        if(i + 1 < h.size() && h[i].fi == h[i+1].fi) continue;
        for(auto j : temp) {
            if(chk[UFT.find(j)]) continue;
            chk[UFT.find(j)] = true;
            if(UFT.is_complete(j)) ans++;
        }
        temp.clear();
        chk.clear();
    }
    cout << max(0, ans - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}