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

const int MAX = 1010101;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll mod = 998244353;

class BIT {
    vector <ll> tree;
    int sz;
public:
    void Init(int n) {
        tree.resize(n+1);
        sz = n;
    }
    void update(int i, ll val) {
        while(i <= sz) {
            tree[i] += val;
            tree[i] %= mod;
            i += (i & -i);
        }
    }
    ll cal(int i) {
        ll ret = 0;
        while(i > 0) {
            ret += tree[i];
            ret %= mod;
            i -= (i & -i);
        }
        return ret;
    }
} fwt;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    fwt.Init(5000);
    for(int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        ll ans = fwt.cal(u-1) + 1;
        cout << ans << ' ';
        fwt.update(u, ans);
    }
}