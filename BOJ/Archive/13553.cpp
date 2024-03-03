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

struct Query {
    int s, e, idx;
};

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
        i = min(i, sz);
        i = max(i, 0);
        int ret = 0;
        while(i > 0) {
            ret += tree[i];
            i -= (i & -i);
        }
        return ret;
    }
} T;

int A[MAX], k;
ll ans[MAX];
Query Q[MAX];
vector <int> num;
ll tans = 0;

void add(int x) {
    tans += T.cal(x + k) - T.cal(x - k - 1);
    T.update(x, 1);
}

void erase(int x) {
    T.update(x, -1);
    tans -= T.cal(x + k) - T.cal(x - k - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> Q[i].s >> Q[i].e;
        Q[i].idx = i;
    }
    sort(Q + 1, Q + q + 1, [](Query a, Query b) {
        if(a.s / 400 != b.s / 400) return a.s / 400 < b.s / 400;
        return a.e < b.e;
    });

    T.init(100000);
    int s = Q[1].s, e = Q[1].e;
    for(int i = s; i <= e; i++) {
        add(A[i]);
    }
    ans[Q[1].idx] = tans;
    for(int i = 2; i <= q; i++) {
        while(Q[i].s < s) {s--; add(A[s]);}
        while(Q[i].e > e) {e++; add(A[e]);}
        while(Q[i].s > s) {erase(A[s]), s++;}
        while(Q[i].e < e) {erase(A[e]), e--;};
        ans[Q[i].idx] = tans;
    }

    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}
