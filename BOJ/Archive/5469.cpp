#include  <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

struct SEG {
    vector <int> tree;
    int sz, mod;
    bool base;
    SEG(int n, int _mod, int x = 0, bool _base = true) : mod(_mod), base(_base) {
        for(sz = 1; sz < n; sz <<= 1) ;
        tree.resize(sz<<1);
        if(x) for(int &i : tree) i = x;
    }

    void update(int x, int val) {
        int node = x + sz - base;
        tree[node] += val;
        tree[node] %= mod;
        while(node >>= 1) {
            tree[node] = (tree[node<<1] * tree[node<<1|1]) % mod;
        }
    }

    int cal(int l, int r) {
        int ret = 1;
        for(l += sz - base, r += sz - base; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) ret = (ret * tree[l++]) % mod;
            if(~r & 1) ret = (ret * tree[r--]) % mod;
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k, mod;
    cin >> n >> k >> mod;
    vector <pii> F(n), C(k);
    for(int i = 0; i < n; i++) {
        cin >> F[i].fi >> F[i].se;
        C[F[i].se-1].fi = max(C[F[i].se-1].fi, F[i].fi);
    }
    for(int i = 0; i < k; i++) {
        C[i].se = i + 1;
    }
    sort(all(F));
    sort(all(C));
    
    vector <int> num(k+1), cnt(k), tcnt(k), acnt(k);
    vector <vector <int> > L(k);
    SEG ST(k, mod, 1, false);
    for(int i = 0; i < k; i++) {
        num[C[i].se] = i;
    }
    for(int i = 0; i < n; i++) {
        F[i].se = num[F[i].se];
        L[F[i].se].eb(F[i].fi);
        cnt[F[i].se]++;
    }

    int ans = 0, idx = 0;
    for(int i = 0; i < n; i++) {
        tcnt[F[i].se]++;
        while(idx < n && F[idx].fi * 2 <= F[i].fi) {
            ST.update(F[idx].se, 1);
            acnt[F[idx].se]++;
            idx++;
        }
        if(tcnt[F[i].se] == cnt[F[i].se]) {
            ans += ST.cal(0, F[i].se);
            ans %= mod;
            int pos = lower_bound(all(C), pii(2*L[F[i].se][acnt[F[i].se]], 0)) - C.begin();
            ans += ST.cal(0, F[i].se-1) * (ST.cal(F[i].se+1, pos-1) - 1);
            ans = ((ans % mod) + mod) % mod;
        }
    }
    cout << ans << endl;
}