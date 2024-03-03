#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define em emplace
#define fi first
#define se second

using namespace std;
typedef long long ll;

struct PST {
    struct Node {
        int l = 0, r = 0, val = 0;
        Node() {}
        Node(int _l, int _r, int _val) : l(_l), r(_r), val(_val) {}
    };
    vector <Node> tree;
    vector <int> root;
    int st, ed;
    PST(int _st, int _ed) : st(_st), ed(_ed) {
        tree.eb(0, 0, 0);
        root.eb(0);
    }

    void expand_tree(int k) {
        root.eb(tree.size());
        int n = root.size() - 1;
        tree.eb(0, 0, 0);
        expand_tree(root[n], root[n-1], st, ed, k);
    }

    void expand_tree(int cnd, int pnd, int s, int e, int k) {
        tree[cnd].val = tree[pnd].val + 1;
        if(s == e) return;
        int m = s + e >> 1;
        if(k <= m) {
            tree[cnd].r = tree[pnd].r;
            tree[cnd].l = tree.size();
            tree.eb(0, 0, 0);
            expand_tree(tree[cnd].l, tree[pnd].l, s, m, k);
        }
        else {
            tree[cnd].l = tree[pnd].l;
            tree[cnd].r = tree.size();
            tree.eb(0, 0, 0);
            expand_tree(tree[cnd].r, tree[pnd].r, m+1, e, k);
        }
    }

    int kth(int l, int r, int k) {
        return kth(root[r], root[l-1], st, ed, k);
    }

    int kth(int cnd, int pnd, int s, int e, int k) {
        if(s == e) return s;
        int m = s + e >> 1;
        int cnt = tree[tree[cnd].l].val - tree[tree[pnd].l].val;
        if(cnt >= k) return kth(tree[cnd].l, tree[pnd].l, s, m, k);
        else return kth(tree[cnd].r, tree[pnd].r, m+1, e, k - cnt);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, K, L, R;
    cin >> N >> K >> L >> R;

    vector <ll> A(N+1), S(N+1), num;

    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        S[i] = S[i-1] + A[i];
        num.eb(S[i]);
    }
    num.eb(0);

    sort(all(num));
    num.erase(unique(all(num)), num.end());
    PST pst(0, num.size()-1);

    for(int i = 0; i <= N; i++) {
        S[i] = lower_bound(all(num), S[i]) - num.begin();
        pst.expand_tree(S[i]);
    }

    // S[i]로 expand한 tree의 root는 root[i+1]에 있음.

    priority_queue <pair <ll, int> > pq;
    for(int i = L; i <= N; i++) {
        int l = max(0, i - R), r = i - L;
        pq.emplace(num[S[i]]-num[pst.kth(l+1, r+1, 1)], i);
    }

    vector <int> cnt(N+1);
    ll ans = 0;
    for(int i = 0; i < K; i++) {
        int x = pq.top().se;
        ans += pq.top().fi;
        pq.pop();
        cnt[x]++;
        int l = max(0, x - R), r = x - L;
        if(r - l >= cnt[x]) pq.emplace(num[S[x]]-num[pst.kth(l+1, r+1, cnt[x] + 1)], x);
    }
    cout << ans << endl;
}