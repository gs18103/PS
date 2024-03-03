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

const int MAX = 2020;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;


struct Slope {
    ll x, y;
    int l;
    Slope(ll x, ll y, int l) : x(x), y(y), l(l) {}
};

bool operator < (const Slope &a, const Slope &b) {
    return a.y * b.x < a.x * b.y;
}

class BinaryIndexedTree {
    vector <int> tree;
    int sz;
public:
    void Init(int n) {
        tree.resize(n+1);
        sz = n;
        for(auto &i : tree) {
            i = n;
        }
    }

    void update(int i, int val) {
        while(i <= sz) {
            tree[i] = min(tree[i], val);
            i += (i & -i);
        }
    }

    int cal(int i) {
        int ret = sz;
        while(i > 0) {
            ret = min(ret, tree[i]);
            i -= (i & -i);
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> h(n+1);
    vector <vector <int> > dp(n+1);
    for(int i = 1; i <= n; i++) {
        dp[i].resize(n+1);
        cin >> h[i];
    }
    if(n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    dp[1][2] = 0;
    vector <BinaryIndexedTree> BIT(n+1);
    vector <vector <Slope> > SLP(n+1);
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            SLP[i].eb(i - j, h[i] - h[j], j);
        }
        sort(all(SLP[i]));
    }
    dp[1][2] = 0;
    BIT[2].Init(1);
    BIT[2].update(1, 0);
    for(int i = 3; i <= n; i++) {
        dp[1][i] = i - 2;
        for(int j = 2; j < i; j++) {
            int idx = upper_bound(all(SLP[j]), Slope(i - j, h[i] - h[j], j)) - SLP[j].begin();
            dp[j][i] = BIT[j].cal(idx) + i - j - 1;
        }
        BIT[i].Init(i-1);
        for(int j = 1; j < i; j++) {
            int idx = lower_bound(all(SLP[i]), Slope(i - j, h[i] - h[j], j)) - SLP[i].begin() + 1;
            BIT[i].update(idx, dp[j][i]);
        }
    }
    int ans = INF;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            ans = min(ans, dp[j][i] + n - i);
        }
    }
    cout << ans << endl;
}