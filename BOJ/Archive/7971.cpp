#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

class BinaryIndexedTree {
    vector <int> tree;
    int sz;
public:
    void Init(int n) {
        tree.resize(n+1);
        sz = n;
    }
    void update(int i, int val) {
        while(i <= sz) {
            tree[i] = max(tree[i], val);
            i += (i & -i);
        }
    }
    int cal(int i) {
        int ret = 0;
        while(i > 0) {
            ret = max(ret, tree[i]);
            i -= (i & -i);
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector <pair <pii, int> > pt(k);
    vector <int> Y;
    for(int i = 0; i < k; i++) {
        cin >> pt[i].fi.fi >> pt[i].fi.se >> pt[i].se;
        Y.eb(pt[i].fi.se);
    }
    sort(all(pt));
    sort(all(Y));
    BinaryIndexedTree BIT;
    BIT.Init(k);
    for(int i = 0; i < k; i++) {
        int y = lower_bound(all(Y), pt[i].fi.se) - Y.begin() + 1;
        BIT.update(y, BIT.cal(y) + pt[i].se);
    }
    cout << BIT.cal(k);
}