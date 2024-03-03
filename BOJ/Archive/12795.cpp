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

class LiChaoSegmentTree {
    struct Node {
        Node *l = nullptr, *r = nullptr;
        pll val;
    } *tree;

public :
    ll cal(pll l, ll x) {
        return (ll)l.fi * x + l.se;
    }
    void add_line(Node *node, pll val, ll s = -1'000'000'000'000, ll e = 1'000'000'000'010) {
        ll m = s + e >> 1;
        bool left = cal(val, s) > cal(node->val, s);
        bool mid = cal(val, m) > cal(node->val, m);
        if(mid) swap(val, node->val);
        if(e == s + 1) return;
        if(left != mid) {
            if(!node->l) {
                node->l = new Node; 
                node->l->val = val;
            }
            else add_line(node->l, val, s, m);
        }
        else {
            if(!node->r) {
                node->r = new Node;
                node->r->val = val;
            }
            else add_line(node->r, val, m, e);
        }
    }

    void Add_line(pll val) {
        if(!tree) {
            tree = new Node;
            tree->val = val;
            return;
        }
        else add_line(tree, val);
    }

    ll cal_max(Node *node, ll x, ll s = -1'000'000'000'000, ll e = 1'000'000'000'010) {
        ll m = s + e >> 1;
        if(e == s + 1) return cal(node->val, x);
        if(x < m) {
            if(node->l) return max(cal(node->val, x), cal_max(node->l, x, s, m));
            else return cal(node->val, x);
        }
        else {
            if(node->r) return max(cal(node->val, x), cal_max(node->r, x, m, e));
            else return cal(node->val, x);
        }
    }

    ll Cal_max(ll x) {
        return cal_max(tree, x);
    }
} LCST;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            ll a, b;
            cin >> a >> b;
            LCST.Add_line({a, b});
        }
        else {
            ll x;
            cin >> x;
            cout << LCST.Cal_max(x) << '\n';
        }
    }
}