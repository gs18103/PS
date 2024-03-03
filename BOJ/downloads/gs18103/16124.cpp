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
const ll LINF = (ll)1e18;
const ll mod = 998244353;

class SegmentTree {
    vector <ll> tree[10], lazy[10];
    vector <ll> exp, exp1;
    int temp[10], temp1[10], temp2[10];
    int sz;
public:
    void Init(string S) {
        sz = S.size();
        int tt = 1;
        while(tt < sz) tt <<= 1;
        tt <<= 1;
        for(int i = 0; i < 10; i++) {
            tree[i].resize(tt);
            lazy[i].resize(tt);
        }
        exp.resize(sz+1);
        exp[0] = 1;
        for(int i = 1; i <= sz; i++) {
            exp[i] = (10 * exp[i-1]) % mod;
        }
        init(1, 1, sz, S);
    }
    void init(int node, int s, int e, string &S) {
        for(int i = 0; i < 10; i++) {
            lazy[i][node] = i;
        }
        if(s == e) {
            tree[S[s-1]-'0'][node] = 1;
            return;
        }
        int m = s + e >> 1;
        init(node<<1, s, m, S);
        init(node<<1|1, m+1, e, S);
        for(int i = 0; i < 10; i++) {
            tree[i][node] = (tree[i][node<<1] * exp[e-m] + tree[i][node<<1|1]) % mod;
        }
    }

    void push(int node, int s, int e) {
        bool flag = false;
        for(int i = 0; i < 10; i++) {
            if(lazy[i][node] != i) {
                flag = true;
                break;
            }
        }
        if(!flag) return;
        for(int i = 0; i < 10; i++) temp[i] = 0;
        for(int i = 0; i < 10; i++) {
            temp[lazy[i][node]] += tree[i][node];
            temp[lazy[i][node]] %= mod;
        }
        for(int i = 0; i < 10; i++) {
            tree[i][node] = temp[i];
        }
        if(s != e) {
            for(int i = 0; i < 10; i++) {
                temp1[i] = lazy[lazy[i][node<<1]][node];
                temp2[i] = lazy[lazy[i][node<<1|1]][node];
            }
            for(int i = 0; i < 10; i++) {
                lazy[i][node<<1] = temp1[i];
                lazy[i][node<<1|1] = temp2[i];
            }
        }
        for(int i = 0; i < 10; i++) lazy[i][node] = i;
    }

    void change(int l, int r, int f, int t) {
        update(1, 1, sz, l, r, f, t);
    }
    void update(int node, int s, int e, int l, int r, int f, int t) {
        push(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            lazy[f][node] = t;
            push(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update(node<<1, s, m, l, r, f, t);
        update(node<<1|1, m+1, e, l, r, f, t);
        for(int i = 0; i < 10; i++) {
            tree[i][node] = (tree[i][node<<1] * exp[e-m] + tree[i][node<<1|1]) % mod;
        }
    }

    ll num(int l, int r) {
        return cal(1, 1, sz, l, r);
    }
    ll cal(int node, int s, int e, int l, int r) {
        push(node, s, e);
        if(s > r || e < l) return 0;
        if(s >= l && e <= r) {
            ll ret = 0;
            for(int i = 0; i < 10; i++) {
                ret += tree[i][node] * i;
                ret %= mod;
            }
            ret = (ret * exp[r-e]) % mod;
            return ret;
        }
        int m = s + e >> 1;
        return (cal(node<<1, s, m, l, r) + cal(node<<1|1, m+1, e, l, r)) % mod;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string S;
    cin >> S;
    SegmentTree ST;
    ST.Init(S);
    int q;
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r, f, t;
            cin >> l >> r >> f >> t;
            ST.change(l, r, f, t);
        }
        if(type == 2) {
            int l, r;
            cin >> l >> r;
            cout << ST.num(l, r) << '\n';
        }
    }

}