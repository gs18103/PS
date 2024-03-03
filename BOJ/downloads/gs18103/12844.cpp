#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[505050];
ll tree[4040404];
ll lazy[4040404];

ll init(int node, int s, int e) {
    int m = (s + e) / 2;
    if(s == e) return tree[node] = arr[s];
    return tree[node] = init(node*2, s, m) ^ init(node*2+1, m+1, e);
}

void update_lazy(int node, int s, int e){
    if((e-s+1) & 1) tree[node] ^= lazy[node];
    if(s != e) {
        lazy[node*2] ^= lazy[node];
        lazy[node*2+1] ^= lazy[node];
    }
    lazy[node] = 0;
}

void update_range(int node, int s, int e, int l, int r, ll val) {
    update_lazy(node, s, e);
    int m = (s + e) / 2;
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        if((e-s+1) & 1) tree[node] ^= val;
        if(s != e) {
            lazy[node*2] ^= val;
            lazy[node*2+1] ^= val;
        }
        return;
    }
    update_range(node*2, s, m, l, r, val);
    update_range(node*2+1, m+1, e, l, r, val);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

ll cal(int node, int s, int e, int l, int r) {
    update_lazy(node, s, e);
    int m = (s + e) / 2;
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[node];
    return cal(node*2, s, m, l, r) ^ cal(node*2+1, m+1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);
    cin >> q;
    while(q--) {
        int t, u, v, w;
        cin >> t >> u >> v;
        if(u > v) swap(u, v);
        if(t == 1) {
            cin >> w;
            update_range(1, 1, n, u+1, v+1, w);
        }
        else if(t == 2) {
            cout << cal(1, 1, n, u+1, v+1) << '\n';
        }
    }
}