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

struct SEG {
    struct Node {
        int mn, orv = 0, andv = 0;
    };

    Node mrg(Node a, Node b) {
        return {min(a.mn, b.mn), a.orv | b.orv, a.andv & b.andv};
    }
    vector <Node> tree;
    vector <int> lazy;
    int n;

    void init(int node, int s, int e, vector <int> &A) {
        if(s == e) {
            tree[node].mn = tree[node].orv = tree[node].andv = A[s-1];
            return;
        }
        int m = (s + e) / 2;
        init(node*2, s, m, A);
        init(node*2+1, m+1, e, A);
        tree[node] = mrg(tree[node*2], tree[node*2+1]);
    }

    void Init(vector <int> &A) {
        n = A.size();
        tree.resize(4*n+10);
        lazy.resize(4*n+10);
        init(1, 1, n, A);
    }

    void update_lazy(int node, int s, int e) {
        tree[node].mn += lazy[node];
        tree[node].andv += lazy[node];
        tree[node].orv += lazy[node];
        if(s != e) {
            for(int i = node * 2; i <= node * 2 + 1; i++) {
                lazy[i] += lazy[node];
            }
        }
        lazy[node] = 0;
    }

    void update(int node, int s, int e, int l, int r, int x, bool flag) {
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r && ((tree[node].andv ^ tree[node].orv) & x) == 0) {
            if(flag) lazy[node] -= (tree[node].andv & x);
            else lazy[node] += x - (tree[node].orv & x);
            update_lazy(node, s, e);
            return;
        }
        int m = (s + e) / 2;
        update(node * 2, s, m, l, r, x, flag);
        update(node * 2 + 1, m + 1, e, l, r, x, flag);
        tree[node] = mrg(tree[node*2], tree[node*2+1]);
    }

    int cal_min(int node, int s, int e, int l, int r) {
        update_lazy(node, s, e);
        if(s > r || e < l) return (int)2e9;
        if(s >= l && e <= r) return tree[node].mn;
        int m = (s + e) / 2;
        return min(cal_min(node*2, s, m, l, r), cal_min(node*2+1, m+1, e, l, r));
    }
} st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    st.Init(A);

    int q;
    cin >> q;
    while(q--) {
        string t;
        int l, r, x;
        cin >> t >> l >> r;
        if(t == "&") {
            cin >> x;
            st.update(1, 1, n, l, r, ~x, 1);
        }
        if(t == "|") {
            cin >> x;
            st.update(1, 1, n, l, r, x, 0);
        }
        if(t == "?") {
            cout << st.cal_min(1, 1, n, l, r) << '\n';
        }
    }
}