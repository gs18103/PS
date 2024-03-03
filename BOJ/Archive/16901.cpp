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

ll ans = 0;
struct Node {
    int l, r, val;
    Node(int l, int r, int val) : l(l), r(r), val(val) {}
};

struct SEG {
    vector <Node> tree;

    void update(int s, int e, int node, int k) {
        tree[node].val++;
        if(s == e) return;
        int m = (s + e) >> 1;
        if(k <= m) {
            if(tree[node].l == 0) {
                tree[node].l = tree.size();
                tree.eb(0, 0, 0);
            }
            update(s, m, tree[node].l, k);
        }
        else {
            if(tree[node].r == 0) {
                tree[node].r = tree.size();
                tree.eb(0, 0, 0);
            }
            update(m+1, e, tree[node].r, k);
        }
    }

    int cal(int s, int e, int k, int node, int b) {
        if(s == e) return s;
        int m = (s + e) >> 1;
        if(tree[tree[node].l].val == 0) return cal(m + 1, e, k, tree[node].r, b - 1);
        if(tree[tree[node].r].val == 0) return cal(s, m, k, tree[node].l, b - 1);
        if((k >> b) & 1) return cal(m + 1, e, k, tree[node].r, b - 1);
        else return cal(s, m, k, tree[node].l, b - 1);
    }
};

void solve(vector <int> arr, int t) {
    if(arr.empty()) return;
    vector <int> a, b;
    for(auto i : arr) {
        if((i >> t) & 1) a.eb(i);
        else b.eb(i);
    }
    if(a.size() < b.size()) swap(a, b);
    if(!b.empty()) {
        SEG st;
        st.tree.eb(0, 0, 0);
        st.tree.eb(0, 0, 0);
        for(auto i : a) {
            st.update(0, (1 << 30) - 1, 1, i);
        }
        int mn = INF;
        for(auto i : b) {
            mn = min(mn, (i ^ st.cal(0, (1 << 30) - 1, i, 1, 29)));
        }
        ans += mn;
    }
    if(t == 0) return;
    solve(a, t - 1);
    solve(b, t - 1);
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector <int> arr;
    for(int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        arr.eb(u);
    }
    solve(arr, 29);
    cout << ans << endl;
}