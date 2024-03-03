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
const ll LINF = (ll)9e18;

class SegmentTree {
public:
    struct Node {
        ll s = 0, lmx = -LINF, rmx = -LINF, smx = -LINF;
        Node operator + (Node b) {
            Node ret;
            ret.s = s + b.s;
            ret.lmx = max(lmx, s + b.lmx);
            ret.rmx = max(b.rmx, rmx + b.s);
            ret.smx = rmx + b.lmx;
            ret.smx = max({ret.smx, smx, b.smx});
            return ret;
        }
    };
    vector <Node> tree; 
    int sz;

    void Init(int n, vector <ll> &A) {
        sz = n;
        tree.resize(4*n+10);
        init(1, n, A);
    }

    void init(int s, int e, vector <ll> &A, int node = 1) {
        if(s == e) {
            tree[node].s = tree[node].lmx = tree[node].rmx = tree[node].smx = A[s];
            return;
        }
        int m = s + e >> 1;
        init(s, m, A, node * 2);
        init(m + 1, e, A, node * 2 + 1);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    Node Cal(int l, int r) {
        return cal(1, sz, l, r);
    }

    Node cal(int s, int e, int l, int r, int node = 1) {
        Node ret;
        if(s > r || e < l) return ret;
        if(s >= l && e <= r) return tree[node];
        int m = (s + e) >> 1;
        ret = cal(s, m, l, r, node * 2) + cal(m + 1, e, l, r, node * 2 + 1);
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <ll> A(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    SegmentTree ST;
    ST.Init(n, A);

    int q;
    cin >> q;
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(y1 < x2) {
            cout << ST.Cal(x1, y1).rmx + ST.Cal(y1 + 1, x2 - 1).s + ST.Cal(x2, y2).lmx << '\n';
        }
        else {
            cout << max({
                ST.Cal(x2, y1).smx, 
                ST.Cal(x1, x2).rmx + max(0LL, ST.Cal(x2 + 1, y2).lmx), 
                ST.Cal(x1, y1).rmx + max(0LL, ST.Cal(y1 + 1, y2).lmx)
            }) << '\n';
        }
    }
}