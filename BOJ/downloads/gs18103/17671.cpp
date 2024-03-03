#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define my_assert cout << "!" << endl;

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = (1 << 30) - 1;
const ll LINF = 1LL << 60;

struct antena {
    int h, a, b;
} arr[2*MAX];

struct SEG {
    vector <pll> tree;
    vector <ll> lazy;

    SEG(int n) {
        tree.resize(4*n+10);
        lazy.resize(4*n+10);
        for(int i = 1; i < tree.size(); i++) {
            tree[i].fi = -1;
            tree[i].se = LINF;
            lazy[i] = -LINF;
        }
    }

    void update_lazy(int node, int s, int e) {
        tree[node].fi = max(tree[node].fi, lazy[node] - tree[node].se);
        if(s != e) {
            lazy[node*2] = max(lazy[node*2], lazy[node]);
            lazy[node*2+1] = max(lazy[node*2+1], lazy[node]);
        }
        lazy[node] = -LINF;
    }

    void update1(int node, int s, int e, int l, int r, int val) {
        if(l > r) return;
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            lazy[node] = max(lazy[node], (ll)val);
            update_lazy(node, s, e);
            return;
        }
        int m = (s + e) / 2;
        update1(node*2, s, m, l, r, val), update1(node*2+1, m+1, e, l, r, val);
        tree[node].fi = max(tree[node*2].fi, tree[node*2+1].fi);
    }

    void update2(int node, int s, int e, int k, bool flag) {
        update_lazy(node, s, e);
        if(s == e) {
            if(flag) tree[node].se = arr[k].h;
            else tree[node].se = LINF;
            return;
        }
        int m = (s + e) / 2;
        if(k <= m) update2(node*2, s, m, k, flag);
        else update2(node*2+1, m+1, e, k, flag);
        tree[node].se = min(tree[node*2].se, tree[node*2+1].se);
    }

    int cal(int node, int s, int e, int l, int r) {
        update_lazy(node, s, e);
        if(s > r || e < l) return -1;
        if(s >= l && e <= r) return tree[node].fi;
        int m = (s + e) / 2;
        return max(cal(node*2, s, m, l, r), cal(node*2+1, m+1, e, l, r));
    }
};

struct Query {
    int l, r, idx;
} Q[2*MAX];
int ans[2*MAX], n, q;

void solve() {
    SEG st(n);
    int idx = 0;
    priority_queue <pii, vector <pii>, greater <pii> > pq1, pq2;
    for(int i = 1; i <= q; i++) {
        while(idx < Q[i].r) {
            while(!pq2.empty() && pq2.top().fi == idx) {
                st.update2(1, 1, n, pq2.top().se, false);
                pq2.pop();
            }
            idx++;
            while(!pq1.empty() && pq1.top().fi == idx) {
                st.update2(1, 1, n, pq1.top().se, true);
                pq1.pop();
            }
            st.update1(1, 1, n, max(1, idx - arr[idx].b), max(0, idx - arr[idx].a), arr[idx].h);
            pq1.em(idx + arr[idx].a, idx);
            pq2.em(idx + arr[idx].b, idx);
        }
        ans[Q[i].idx] = max(ans[Q[i].idx], st.cal(1, 1, n, Q[i].l, Q[i].r));
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].h >> arr[i].a >> arr[i].b;
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].idx = i;
        ans[i] = -1;
    }
    sort(Q+1, Q+q+1, [](Query a, Query b) {
        return a.r < b.r;
    });
    solve();
    for(int i = 1; i <= n; i++) {
        arr[i].h = - arr[i].h;
    }
    solve();
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}