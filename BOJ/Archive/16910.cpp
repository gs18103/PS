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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int T[MAX];
ll L[MAX], R[MAX];

struct SEG {
    vector <int> tree;
    vector <pii> lazy;
    int sz;
    void Init(int n) {
        sz = n;
        tree.resize(4*n+10);
        lazy.resize(4*n+10);
        fill(all(lazy), pii(1, 0));
    }

    void update_lazy(int node, int s, int e) {
        tree[node] = tree[node] * lazy[node].fi + lazy[node].se * (e - s + 1);
        if(s != e) {
            lazy[node<<1].fi *= lazy[node].fi;
            lazy[node<<1].se *= lazy[node].fi;
            lazy[node<<1].se += lazy[node].se;
            lazy[node<<1|1].fi *= lazy[node].fi;
            lazy[node<<1|1].se *= lazy[node].fi;
            lazy[node<<1|1].se += lazy[node].se;
        }
        lazy[node] = {1, 0};
    }

    void update(int node, int s, int e, int l, int r, pii val) {
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            lazy[node] = val;
            update_lazy(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update(node<<1, s, m, l, r, val);
        update(node<<1|1, m+1, e, l, r, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
    void update(int l, int r, pii val) {update(1, 1, sz, l, r, val);}

    int mex(int node, int s, int e) {
        update_lazy(node, s, e);
        if(s == e) return s;
        int m = s + e >> 1;
        update_lazy(node<<1, s, m);
        if(tree[node<<1] < (m - s + 1)) return mex(node<<1, s, m);
        else return mex(node<<1|1, m+1, e);
    }
    int mex() {return mex(1, 1, sz);}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    vector <ll> num;
    for(int i = 1; i <= q; i++) {
        cin >> T[i] >> L[i] >> R[i];
        num.eb(L[i]);
        num.eb(L[i]+1);
        if(L[i]) num.eb(L[i]-1);
        num.eb(R[i]);
        num.eb(R[i]+1);
        if(R[i]) num.eb(R[i]-1);
    }
    num.eb(0);
    num.eb(1);
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    SEG ST;
    ST.Init(num.size());

    for(int i = 1; i <= q; i++) {
        L[i] = lower_bound(all(num), L[i]) - num.begin();
        R[i] = lower_bound(all(num), R[i]) - num.begin();
        if(T[i] == 1) ST.update(L[i], R[i], pii(0, 1));
        if(T[i] == 2) ST.update(L[i], R[i], pii(0, 0));
        if(T[i] == 3) ST.update(L[i], R[i], pii(-1, 1));
        cout << num[ST.mex()] << '\n';
    }
}