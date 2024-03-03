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

ll d[MAX], p[MAX], s[MAX], dp[MAX];

struct LiChaoSegmentTree {
    struct Node {
        Node *l = nullptr, *r = nullptr;
        pll val;
        Node(pll val) : val(val) {}
    } *tree = nullptr;

    ll cal(pll l, ll x) {
        return (ll)l.fi * x + l.se;
    }
    void add_line(Node *node, pll val, ll s = 0, ll e = 1e8 + 1) { // modify s & e
        ll m = s + e >> 1;
        bool left = cal(val, s) < cal(node->val, s); // > if max
        bool mid = cal(val, m) < cal(node->val, m); // > if max
        if(mid) swap(val, node->val);
        if(e == s + 1) return;
        if(left != mid) {
            if(!node->l) node->l = new Node(val);
            else add_line(node->l, val, s, m);
        }
        else {
            if(!node->r) node->r = new Node(val);
            else add_line(node->r, val, m, e);
        }
    }

    void add(pll val) {
        if(!tree) tree = new Node(val);
        else add_line(tree, val);
    }

    ll query(Node *node, ll x, ll s = 0, ll e = 1e8 + 1) { // modify s & e
        if(!node) return LINF; // -LINF if max
        ll m = s + e >> 1;
        if(e == s + 1) return cal(node->val, x);
        if(x < m) return min(cal(node->val, x), query(node->l, x, s, m));
        else return min(cal(node->val, x), query(node->r, x, m, e));
    }

    ll query(ll x) {
        if(!tree) return LINF; // -LINF if max
        return query(tree, x);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        d[i] = d[i-1] + u;
    }
    for(int i = 1; i < n; i++) {
        cin >> p[i] >> s[i];
    }
    dp[1] = 0;
    LiChaoSegmentTree CHT;
    CHT.add(pll(s[1], p[1]));
    for(int i = 2; i <= n; i++) {
        dp[i] = CHT.query(d[i]);
        CHT.add(pll(s[i], p[i] - d[i] * s[i] + dp[i]));
    }
    cout << dp[n] << endl;
}