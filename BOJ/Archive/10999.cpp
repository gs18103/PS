#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll arr[1010101];
ll tree[8080808];
ll lazy[8080808];

ll init(int node, int s, int e) {
    int m = (s + e) / 2;
    if(s == e) return tree[node] = arr[s];
    return tree[node] = init(node*2, s, m) + init(node*2+1, m+1, e);
}

void update_lazy(int node, int s, int e){
    tree[node] += (ll)(e-s+1) * lazy[node];
    if(s != e) {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update_range(int node, int s, int e, int l, int r, ll diff) {
    update_lazy(node, s, e);
    int m = (s + e) / 2;
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        tree[node] += (ll)(e-s+1) * diff;
        if(s != e) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    update_range(node*2, s, m, l, r, diff);
    update_range(node*2+1, m+1, e, l, r, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll cal(int node, int s, int e, int l, int r) {
    update_lazy(node, s, e);
    int m = (s + e) / 2;
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[node];
    return cal(node*2, s, m, l, r) + cal(node*2+1, m+1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);
    int q = m + k;
    while(q--) {
        int t, u, v;
        ll w;
        cin >> t >> u >> v;
        if(t == 1) {
            cin >> w;
            update_range(1, 1, n, u, v, w);
        }
        else if(t == 2) {
            cout << cal(1, 1, n, u, v) << '\n';
        }
    }
}