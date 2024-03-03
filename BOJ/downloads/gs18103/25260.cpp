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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

struct SEG {
    vector <pii> tree;
    int sz;
    bool base;

    SEG(int n, bool _base = true) : base(_base) {
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.resize(sz<<1);
        for(auto &i : tree) i = pii(INF, 0);
    }

    void update(int k, pii val) {
        int node = k + sz - base;
        tree[node] = min(tree[node], val);
        while(node >>= 1) tree[node] = min(tree[node<<1], tree[node<<1|1]);
    }

    pii cal(int l, int r) {
        pii ret = pii(INF, 0);
        for(l += sz - base, r += sz - base; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) ret = min(ret, tree[l++]);
            if(~r & 1) ret = min(ret, tree[r--]);
        }
        return ret;
    }
};

vector <int> p[20];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector <int> num;
    vector <int> S(n), E(n);

    for(int i = 0; i < n; i++) {
        cin >> S[i] >> E[i];
        num.eb(S[i]), num.eb(E[i]);
    }
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    SEG ST(num.size(), false);
    for(int i = 0; i < n; i++) {
        S[i] = lower_bound(all(num), S[i]) - num.begin();
        E[i] = lower_bound(all(num), E[i]) - num.begin();
        ST.update(E[i], pii(S[i], i));
    }

    p[0].resize(n);
    for(int i = 0; i < n; i++) {
        p[0][i] = ST.cal(S[i], E[i]).se;
    }
    for(int i = 1; i < 20; i++) {
        p[i].resize(n);
        for(int j = 0; j < n; j++) {
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }

    while(q--) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        if(s == e) {
            cout << "0\n";
            continue;
        }
        if(E[e] < E[s]) {
            cout << "impossible\n";
            continue;
        }

        int ans = 0, cur = e;
        for(int i = 19; i >= 0; i--) {
            if(S[p[i][cur]] > E[s]) cur = p[i][cur], ans += (1 << i);
        }
        if(S[cur] > E[s]) ans++, cur = p[0][cur];
        if(S[cur] > E[s]) cout << "impossible\n";
        else cout << ans + 1 << '\n';
    }
}