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

struct BIT {
    vector <int> tree;
    int sz;
    void init(int n) {
        tree.resize(n+1);
        sz = n;
    }

    void update(int i, int val) {
        while(i <= sz) {
            tree[i] += val;
            i += (i & -i);
        }
    }

    int cal(int i) {
        int ret = 0;
        while(i > 0) {
            ret += tree[i];
            i -= (i & -i);
        }
        return ret;
    }
} even, odd;

int arr[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    even.init(n), odd.init(n);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        if(arr[i] & 1) odd.update(i, 1);
        else even.update(i, 1);
    }

    int q;
    cin >> q;
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            if(arr[x] & 1) odd.update(x, -1);
            else even.update(x, -1);
            arr[x] = y;
            if(arr[x] & 1) odd.update(x, 1);
            else even.update(x, 1);
        }
        if(t == 2) cout << even.cal(y) - even.cal(x-1) << '\n';
        if(t == 3) cout << odd.cal(y) - odd.cal(x-1) << '\n';
    }
}