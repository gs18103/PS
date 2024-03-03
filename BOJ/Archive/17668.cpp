#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = (1 << 30) - 1;
const ll LINF = 1LL << 60;

int ans[MAX], n, q;
pii arr[MAX];
vector <int> S, T[MAX], tree[MAX];
struct Query {
    int a, b, c, idx;
} query[MAX];

void update(int x, int y, int val) {
    x = upper_bound(all(S), x) - S.begin();
    while(x <= n) {
        int temp = upper_bound(all(T[x]), y) - T[x].begin();
        while(temp <= T[x].size()) {
            tree[x][temp] += val;
            temp += (temp & -temp);
        }
        x += (x & -x);
    }
}

int cal(int x, int y) {
    x = upper_bound(all(S), x) - S.begin();
    int ret = 0;
    while(x > 0) {
        int temp = upper_bound(all(T[x]), y) - T[x].begin();
        while(temp > 0) {
            ret += tree[x][temp];
            temp -= (temp & -temp);
        }
        x -= (x & -x);
    }
    return ret;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].fi >> arr[i].se;
        S.eb(arr[i].fi);
    }
    sort(all(S));
    for(int i = 1; i <= n; i++) {
        int temp = upper_bound(all(S), arr[i].fi) - S.begin();
        while(temp <= n) {
            T[temp].eb(arr[i].se);
            temp += (temp & -temp);
        }
    }
    for(int i = 1; i <= n; i++) {
        tree[i].resize(T[i].size()+10);
        sort(all(T[i]));
    }
    sort(arr+1, arr+n+1, [](pii a, pii b) {
        return a.fi + a.se > b.fi + b.se;
    });
    
    for(int i = 1; i <= q; i++) {
        cin >> query[i].a >> query[i].b >> query[i].c;
        query[i].idx = i;
    }
    sort(query+1, query+q+1, [](Query X, Query Y) {
        return X.c > Y.c;
    });
    int idx = 1;
    for(int i = 1; i <= q; i++) {
        while(idx <= n && arr[idx].fi + arr[idx].se >= query[i].c) {
            update(arr[idx].fi, arr[idx].se, 1);
            idx++;
        }
        ans[query[i].idx] = cal(1000000000, 1000000000) - cal(1000000000, query[i].b-1) - cal(query[i].a-1, 1000000000) + cal(query[i].a-1, query[i].b-1);
    }
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}