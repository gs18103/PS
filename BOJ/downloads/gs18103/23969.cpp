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
    vector <int> cnt(n);
    set <int> st;

    BIT.Init(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(all(num), a[i]) - num.begin();
        cnt[i] = i - BIT.cal(a[i]);
        v[cnt[i]].eb(i);
        if(cnt[i] > 0) st.em(i);
        sum += cnt[i];
        BIT.update(a[i], 1);
    }
    if(sum < k) {
        cout << -1;
        return 0;
    }

    for(int i = 1; i < n; i++) {
        if(k <= st.size()) {
            vector <int> ans(n);
            vector <pii> inv;
            BinaryIndexedTree BIT2;
            BIT2.Init(n);
            for(int j = 0; j < i; j++) {
                for(auto x : v[j]) inv.eb(num[a[x]], 0);
            }
            auto it = st.begin();
            for(int j = 1; j <= k; j++) {
                inv.eb(num[a[*it]], cnt[*it] - i);
                it = next(it);
            }
            while(it != st.end()) {
                inv.eb(num[a[*it]], cnt[*it] - i + 1);
                it = next(it);
            }
            sort(all(inv));

            for(int j = 0; j < n; j++) {
                int lb = 0, ub = n - 1;
                while(lb < ub) {
                    int m = lb + ub >> 1;
                    if(m - BIT2.cal(m+1) >= inv[j].se) ub = m;
                    else lb = m + 1;
                }
                ans[lb] = inv[j].fi;
                BIT2.update(lb+1, 1);
            }
            for(auto j : ans) cout << j << ' ';

            return 0;
        }
        k -= st.size();
        for(auto j : v[i]) st.erase(j);
    }
}