#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define em emplace

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int INF = 1e9;
const ll LINF = 1e18;

struct SEG {
    vector <ll> tree, lazy;
    int sz;
    
    SEG(int n) : sz(n) {
        tree.resize(4*n+10), lazy.resize(4*n+10);
    }
    
    void update_lazy(int node, int s, int e) {
        tree[node] = max(tree[node], lazy[node]);
        if(s != e) {
            lazy[node<<1] = max(lazy[node], lazy[node<<1]);
            lazy[node<<1|1] = max(lazy[node], lazy[node<<1|1]);
        }
        lazy[node] = 0;
    }
    
    void update(int l, int r, ll val) {
        update(1, 1, sz, l, r, val);
    }
    void update(int node, int s, int e, int l, int r, ll val) {
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            lazy[node] = max(lazy[node], val);
            update_lazy(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update(node<<1, s, m, l, r, val);
        update(node<<1|1, m+1, e, l, r, val);
        tree[node] = max(tree[node<<1], tree[node<<1|1]);
    }
    
    ll get(int k) {
        return get(1, 1, sz, k);
    }
    ll get(int node, int s, int e, int k) {
        update_lazy(node, s, e);
        if(s == e) return tree[node];
        int m = s + e >> 1;
        if(k <= m) return get(node<<1, s, m, k);
        else return get(node<<1|1, m+1, e, k);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector <ll> h(n+2);
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    
    SEG ST(n);
    
    vector <int> v;
    priority_queue <pair <ll, pii> > pq;
    v.eb(0);
    for(int i = 1; i <= n + 1; i++) {
        while(!pq.empty() && pq.top().fi > h[i]) {
            ll val = pq.top().fi;
            int x = pq.top().se.fi, l = pq.top().se.se;
            pq.pop();
            ST.update(x, x, val * (i - 2 - l));
        }
        while(!v.empty() && h[v.back()] > h[i]) {
            int x = v.back();
            v.pop_back();
            int mxlen = i - 1 - v.back();
            ST.update(1, v.back(), h[x] * mxlen);
            ST.update(v.back() + 1, i - 1, h[x] * (mxlen - 1));
            ST.update(i, n, h[x] * mxlen);
            pq.em(h[x], pii(i, v.back()));
        }
        while(!v.empty() && h[v.back()] == h[i]) v.pop_back();
        v.eb(i);
    }
    
    while(!pq.empty()) pq.pop();
    v.clear();
    v.eb(0);
    reverse(all(h));
    for(int i = 1; i <= n + 1; i++) {
        while(!pq.empty() && pq.top().fi > h[i]) {
            ll val = pq.top().fi;
            int x = pq.top().se.fi, l = pq.top().se.se;
            pq.pop();
            ST.update(x, x, val * (i - 2 - l));
        }
        while(!v.empty() && h[v.back()] > h[i]) {
            int x = v.back();
            v.pop_back();
            int mxlen = i - 1 - v.back();
            pq.em(h[x], pii(n - i + 1, v.back()));
        }
        while(!v.empty() && h[v.back()] == h[i]) v.pop_back();
        v.eb(i);
    }
    
    for(int i = 1; i <= n; i++) {
        cout << ST.get(i) << ' ';
    }
    cout << endl;

    return 0;
}