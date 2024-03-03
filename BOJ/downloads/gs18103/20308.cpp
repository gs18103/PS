#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = (int)1e9;
const ll LINF = (ll)1e63;

pair <pll, pll> sq[MAX];
pll base = {0, 0};
vector <int> st, ed;
ll tree[4*MAX];
ll area[MAX];

ll ccw(pll a, pll b, pll c) {
    return (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
}

void update(int node, int s, int e, int k, ll val) {
    if(s == e) {
        tree[node] = val;
        return;
    }
    int m = (s + e) / 2;
    if(k <= m) update(node * 2, s, m, k, val);
    else update(node * 2 + 1, m + 1, e, k, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll cal(int node, int s, int e, int l, int r) {
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[node];
    int m = (s + e) / 2;
    return cal(node * 2, s, m ,l, r) + cal(node * 2 + 1, m + 1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false);

    int W, H, L, N;
    cin >> W >> H >> L >> N;
    
    for(int i = 1; i <= N; i++) {
        ll x, y, w, h;
        cin >> x >> y >> w >> h;
        sq[i] = {{x + w, y}, {x, y + h}};
        st.eb(i), ed.eb(i);
    }
    sort(sq + 1, sq + N + 1, [](pair <pll, pll> a, pair <pll, pll> b) {
        if(ccw(base, a.fi, b.fi) > 0) return true;
        if(ccw(base, a.fi, b.fi) == 0) return a.fi < b.fi;
        return false;
    });
    sort(all(ed), [](int a, int b) {
        if(ccw(base, sq[a].se, sq[b].se) > 0) return true;
        if(ccw(base, sq[a].se, sq[b].se) == 0) return sq[a].fi < sq[b].fi;
        else return false;
    });

    for(int i = 1; i <= N; i++) {
        area[i] = (sq[i].fi.fi - sq[i].se.fi) * (sq[i].se.se - sq[i].fi.se);
    }

    pll s = {W, 0}, e;
    int ps = 0, pe = 0;
    ll ans = 0; 
    if(L <= H) e = {W, L};
    else e = {W - L + H, H};
    while(e.fi >= 0) {
        while(ps < st.size() && ccw(base, s, sq[st[ps]].fi) < 0) {
            update(1, 1, N, st[ps], 0);
            ps++;
        }
        while(pe < ed.size() && ccw(base, e, sq[ed[pe]].se) <= 0) {
            update(1, 1, N, ed[pe], area[ed[pe]]);
            pe++;
        }
        if(ps >= st.size()) break;
        ans = max(ans, cal(1, 1, N, st[ps], N));
        if(s.se < H) s.se++;
        else s.fi--;
        if(e.se < H) e.se++;
        else e.fi--;
    }
    cout << ans << endl;
}