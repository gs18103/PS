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

const int MAX = 303030;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

struct Query {
    int lb, ub, idx;
    Query(int lb, int ub, int idx) : lb(lb), ub(ub), idx(idx) {}
    bool operator < (Query b) {
        return lb + ub < b.lb + b.ub;
    }
};

class BinaryIndexedTree {
    vector <ll> tree;
    int sz;
public:
    void Init(int n) {
        sz = n;
        tree.resize(n+1);
    }
    void update(int l, int r, ll val) {
        while(l <= sz) {
            tree[l] += val;
            l += (l & -l);
        }
        r++;
        while(r <= sz) {
            tree[r] -= val;
            r += (r & -r);
        }
    }
    ll cal(int i) {
        ll ret = 0;
        while(i > 0) {
            ret += tree[i];
            i -= (i & -i);
        }
        return ret;
    }
    void clear() {
        for(auto &i : tree) i = 0;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <int> p(n+1);
    vector <vector <int> > pos(n+1);
    for(int i = 1; i <= m; i++) {
        int u;
        cin >> u;
        pos[u].eb(i);
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int q;
    cin >> q;
    vector <int> l(q+10), r(q+10);
    vector <ll> w(q+10);
    for(int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i] >> w[i];
    }

    vector <Query> Q;
    for(int i = 1; i <= n; i++) {
        Q.eb(1, q + 1, i);
    }
    
    BinaryIndexedTree BIT;
    BIT.Init(m);
    bool flag = false;
    while(!flag) {
        sort(all(Q));
        flag = true;
        int idx = 1;
        BIT.clear();
        for(auto &i : Q) {
            if(i.lb == i.ub) continue;
            flag = false;
            int mi = (i.lb + i.ub) / 2;
            while(idx <= mi) {
                if(l[idx] <= r[idx]) {
                    BIT.update(l[idx], r[idx], w[idx]);
                }
                else {
                    BIT.update(l[idx], m, w[idx]);
                    BIT.update(1, r[idx], w[idx]);
                }
                idx++;
            }
            ll sum = 0;
            for(auto j : pos[i.idx]) {
                sum += BIT.cal(j);
                if(sum >= p[i.idx]) break;
            }
            if(sum >= p[i.idx]) i.ub = mi;
            else i.lb = mi + 1;
        }
    }

    vector <int> ans(n+1);
    for(auto i : Q) ans[i.idx] = i.lb;
    for(int i = 1; i <= n; i++) {
        if(ans[i] == q + 1) cout << "NIE\n";
        else cout << ans[i] << '\n';
    }
}