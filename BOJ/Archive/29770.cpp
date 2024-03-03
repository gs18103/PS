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
    vector <int> tree;
    int sz;
    bool base;

    SEG(int n, bool _base = true) : base(_base) {
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.resize(sz<<1);
    }

    void update(int k, int val) {
        int node = k + sz - base;
        tree[node] = max(tree[node], val);
        while(node >>= 1) tree[node] = max(tree[node<<1], tree[node<<1|1]);
    }

    int cal(int l, int r) {
        int ret = 0;
        for(l += sz - base, r += sz - base; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) ret = max(ret, tree[l++]);
            if(~r & 1) ret = max(ret, tree[r--]);
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> A(n+1), L(n+1), R(n+1);
    vector <bool> chk(n+1);
    
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    int idx = 1;
    for(int i = 1; i <= n; i++) {
        while(chk[A[i]]) {
            chk[A[idx]] = false;
            idx++;
        }
        chk[A[i]] = true;
        L[i] = i - idx + 1;
    }
    for(int i = 1; i <= n; i++) chk[i] = false;
    idx = n;
    SEG ST(n);
    for(int i = n; i >= 1; i--) {
        while(chk[A[i]]) {
            chk[A[idx]] = false;
            idx--;
        }
        R[i] = idx - i + 1;
        chk[A[i]] = true;
        ST.update(i, R[i]);
    }
    
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(r - L[r] < l) cout << r - l + 1 << '\n';
        else cout << max(ST.cal(l, r - L[r]), L[r]) << '\n';
    }
}