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

const int MAX = 505050;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

pair <int, char> arr[MAX];
int B[MAX], G[MAX], R[MAX];

struct p {
    ll x, y, z;
    p(ll x, ll y, ll z) : x(x), y(y), z(z) {}
};
vector <p> po;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int l; string c;
        cin >> l >> c;
        arr[i] = make_pair(l, c[0]);
    }
    sort(arr+1, arr+n+1);
    for(int i = 1; i <= n; i++) {
        R[i] = R[i-1], G[i] = G[i-1], B[i] = B[i-1];
        if(arr[i].se == 'R') R[i]++;
        if(arr[i].se == 'G') G[i]++;
        if(arr[i].se == 'B') B[i]++;
    }

    po.eb(0, 0, 0);
    for(int i = 1; i <= n; i++) {
        int idx = lower_bound(arr+1, arr+n+1, make_pair(arr[i].fi*2, ' '))-arr-1;
        po.eb(R[idx] - R[i-1] + 1, G[idx] - G[i-1] + 1, B[idx] - B[i-1] + 1);
    }
    sort(all(po), [](p a, p b) {
        return a.z < b.z;
    });

    map <ll, ll> mp;
    ll ans = 0, area = 0;
    mp[0] = LINF;
    mp[LINF] = 0;
    for(int i = n; i >= 1; i--) {
        if(mp.lower_bound(po[i].x)->se >= po[i].y) {
            ans += area * (po[i].z - po[i-1].z);
            continue;
        }
        auto it = mp.lower_bound(po[i].x);
        area -= (po[i].x - prev(it)->fi) * it->se;
        mp[po[i].x] = po[i].y;
        it = mp.find(po[i].x);
        while(prev(it)->se < it->se) {
            area -= prev(it)->se * (prev(it)->fi - prev(prev(it))->fi);
            mp.erase(prev(it)->fi);
            it = mp.find(po[i].x);
        }
        area += (po[i].x - prev(it)->fi) * po[i].y;
        ans += area * (po[i].z - po[i-1].z);
    }
    cout << ans - 1;
}