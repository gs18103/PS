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
    int s, e, k, idx;
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
} TA, TB;

ll A[MAX], B[MAX], cntA[MAX], cntB[MAX];
ll ans[MAX];
Query Q[MAX];

void add(int x) {
    TA.update(A[x], 1);
    cntA[A[x]]++;
    TB.update(B[x], 1);
    cntB[B[x]]++;
}

void erase(int x) {
    TA.update(A[x], -1);
    cntA[A[x]]--;
    TB.update(B[x], -1);
    cntB[B[x]]--;
}

ll get_ans(int k) {
    ll tans = 0;
    int i;
    for(i = 1; i * i <= k; i++) {
        tans += cntA[i] * TB.cal(k / i);
        tans += cntB[i] * TA.cal(k / i);
    }
    i--;
    tans -= TA.cal(i) * TB.cal(i);

    return tans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> Q[i].s >> Q[i].e >> Q[i].k;
        Q[i].idx = i;
    }
    sort(Q + 1, Q + q + 1, [](Query a, Query b) {
        if(a.s / 400 != b.s / 400) return a.s / 400 < b.s / 400;
        return a.e < b.e;
    });

    TA.init(100000);
    TB.init(100000);
    int s = Q[1].s, e = Q[1].e;
    for(int i = s; i <= e; i++) {
        add(i);
    }
    ans[Q[1].idx] = get_ans(Q[1].k);
    for(int i = 2; i <= q; i++) {
        while(Q[i].s < s) {s--; add(s);}
        while(Q[i].e > e) {e++; add(e);}
        while(Q[i].s > s) {erase(s), s++;}
        while(Q[i].e < e) {erase(e), e--;};
        ans[Q[i].idx] = get_ans(Q[i].k);
    }

    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}
