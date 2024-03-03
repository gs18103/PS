#pragma GCC optimize("O3")
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

const int MAX = 1010101;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

struct SEG {
    vector <pll> tree; //sum of p or q

    SEG() {
        tree.resize(2*MAX + 10);
    }

    pll mer(pll a, pll b) {
        return {a.fi + b.fi, a.se + b.se};
    }

    void update(int k, ll val) {
        while(k <= 2*MAX) {
            tree[k] = mer(tree[k], {val, 1});
            k += (k & -k);
        }
    }

    pll cal(int k) {
        pll ret = {0, 0};
        while(k > 0) {
            ret = mer(ret, tree[k]);
            k -= (k & -k);
        }
        return ret;
    }

    pll sum(int l, int r) {
        pll rs = cal(r);
        pll ls = cal(l-1);
        return {rs.fi - ls.fi, rs.se - ls.se};
    }
};

pii arr[MAX];
int p[MAX], q[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        arr[i].fi = p[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> q[i];
        arr[i].se = q[i];
    }
    ll ans = 0;
    
    SEG stpu, stqu;
    sort(arr+1, arr+n+1, [](pii a, pii b){
        return a.se - a.fi < b.se - b.fi;
    });

    for(int i = 1; i <= n; i++) {
        stpu.update(arr[i].fi + arr[i].se, arr[i].fi);
        stqu.update(arr[i].fi + arr[i].se, arr[i].se);
        pll s = stqu.sum(1, arr[i].fi + arr[i].se - 1);
        ans -= s.se * arr[i].se - s.fi;
        s = stpu.sum(arr[i].fi + arr[i].se, 2*MAX);
        ans -= s.fi - s.se * arr[i].fi;
    }

    ans *= 2;

    sort(p+1, p+n+1);
    sort(q+1, q+n+1);
    for(int i = 1; i <= n; i++) {
        ans += 2 * (ll)p[i] * (2 * i - n - 1);
    }
    for(int i = 1; i <= n; i++) {
        ans += 2 * (ll)q[i] * (2 * i - n - 1);
    }
    cout << ans << endl;
}