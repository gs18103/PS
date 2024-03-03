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

struct BinaryIndexedTree {
    vector <int> tree;
    int sz;
    void Init(int n) {
        sz = n;
        tree.resize(n+1);
    }
    void update(int i, int val) {
        for(; i <= sz; i += i & -i) {
            tree[i] += val;
        }
    }
    int cal(int i) {
        int ret = 0;
        for(; i > 0; i -= i & -i) {
            ret += tree[i];
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; ll k;
    cin >> n >> k;
    vector <int> a(n), num;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    num = a;
    num.eb(0);
    sort(all(num));

    BinaryIndexedTree BIT;
    vector <vector <int> > v(n);
    set <int> st;

    BIT.Init(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(all(num), a[i]) - num.begin();
        int temp = i - BIT.cal(a[i] - 1);
        v[temp].eb(i);
        if(temp > 0) st.em(i);
        sum += temp;
        BIT.update(a[i], 1);
    }
    if(sum < k) {
        cout << -1;
        return 0;
    }

    for(int i = 1; i < n; i++) {
        if(k <= st.size()) {
            auto it = st.begin();
            for(int j = 1; j < k; j++) {
                it = next(it);
            }
            int x = *it;
            vector <int> temp;
            for(int j = 0; j < x; j++) {
                temp.eb(num[a[j]]);
            }
            sort(all(temp));
            cout << num[a[x]] << ' ' << temp[x-i];
            return 0;
        }
        k -= st.size();
        for(auto j : v[i]) st.erase(j);
    }
}