#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

struct Query {
    int l, r, idx;
    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
};

int arr[MAX], cnt[10*MAX], ans[MAX], dn, sz;
vector <Query> query;

void add(int num) {
    if(++cnt[num] == 1) dn++;
}

void erase(int num) {
    if(--cnt[num] == 0) dn--;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        query.eb(l, r, i);
    }
    sz = (int)sqrt(n);
    sort(all(query), [](Query &a, Query &b) {
        int idxl = a.r / sz, idxr = b.r / sz;
        if(idxl == idxr) return a.l < b.l;
        return idxl < idxr;
    });

    int l = 1, r = 1;
    add(arr[1]);
    for(auto cur : query) {
        int nl = cur.l, nr = cur.r;
        for(int i = l; i < nl; i++) erase(arr[i]);
        for(int i = l - 1; i >= nl; i--) add(arr[i]);
        for(int i = r; i > nr; i--) erase(arr[i]);
        for(int i = r + 1; i <= nr; i++) add(arr[i]);
        l = nl, r = nr;
        ans[cur.idx] = dn;
    }
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}