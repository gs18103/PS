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

const int MAX = 2020202;
const int INF = 1e9;
const ll LINF = 9e18;

class SegmentTree {
    vector <int> lazy;
    int sz;
public:
    SegmentTree(int n) {
        sz = n;
        lazy.resize(4*n+10);
    }

    void update_lazy(int node, int s, int e) {
        if(s != e) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
            lazy[node] = 0;
        }
    }
    void update(int node, int s, int e, int l, int r, int val) {
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            lazy[node] += val;
            update_lazy(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update(node<<1, s, m, l, r, val);
        update(node<<1|1, m+1, e, l, r, val);
    }
    void Update(int l, int r, int val) {
        update(1, 0, sz-1, l, r, val);
    }
    int get_kth(int k) {
        return cal(1, 0, sz-1, k);
    }
    int cal(int node, int s, int e, int k) {
        if(s == e) return lazy[node];
        update_lazy(node, s, e);
        int m = s + e >> 1;
        if(k <= m) return cal(node<<1, s, m, k);
        else return cal(node<<1|1, m+1, e, k);
    }
};

int ans[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s;
    cin >> s;
    int odd = 0, even = 0;
    vector <pair <pii, int> > Query;
    bool flag = true;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == '-') {
            flag = !flag;
            continue;
        }
        if(flag) {
            Query.eb(make_pair(0, odd), s[i] - '0');
            odd++;
        }
        else {
            Query.eb(make_pair(0, even), s[i] - '0');
            even++;
        }
    }
    int tt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '-') {
            flag = !flag;
            continue;
        }
        if(flag) {
            tt++;
            if(even > 0) Query.eb(make_pair(tt, even - 1 + tt), s[i] - '0');
            odd--;
        }
        if(!flag) {
            tt++;
            if(odd > 0) Query.eb(make_pair(tt, odd - 1 + tt), s[i] - '0');
            even--;
        }
    }

    SegmentTree ST(s.size());
    for(auto i : Query) {
        ST.Update(i.fi.fi, i.fi.se, i.se);
    }
    for(int i = 0; i < s.size(); i++) {
        ans[i] = ST.get_kth(i);
    }
    for(int i = 0; i < s.size() + 100; i++) {
        int digit = 10;
        for(int j = 1; ans[i] >= digit; j++) {
            ans[i+j] += (ans[i] / digit) % 10;
            digit *= 10;
        }
        ans[i] %= 10;
    }
    flag = false;
    for(int i = s.size() + 99; i >= 0; i--) {
        if(ans[i] > 0) flag = true;
        if(flag) {
            cout << ans[i];
        }
    }
}