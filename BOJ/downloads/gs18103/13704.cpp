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


int A[MAX], B[MAX], k, cnt[1<<21];
ll ans[MAX], tans = 0;
Query Q[MAX];

void add(int x) {
    tans += cnt[B[x]^k];
    cnt[B[x]]++;
}

void erase(int x) {
    cnt[B[x]]--;
    tans -= cnt[B[x]^k];
}

ll get_ans() {
    return tans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        B[i] = B[i-1] ^ A[i];
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> Q[i].s >> Q[i].e;
        Q[i].s--;
        Q[i].idx = i;
    }
    sort(Q + 1, Q + q + 1, [](Query a, Query b) {
        if(a.s / 400 != b.s / 400) return a.s / 400 < b.s / 400;
        return a.e < b.e;
    });
    int s = Q[1].s, e = Q[1].e;
    for(int i = s; i <= e; i++) {
        add(i);
    }
    ans[Q[1].idx] = get_ans();
    for(int i = 2; i <= q; i++) {
        while(Q[i].s < s) {s--; add(s);}
        while(Q[i].e > e) {e++; add(e);}
        while(Q[i].s > s) {erase(s), s++;}
        while(Q[i].e < e) {erase(e), e--;};
        ans[Q[i].idx] = get_ans();
    }

    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}
