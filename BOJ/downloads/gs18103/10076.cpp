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
const int INF = INT_MAX >> 1;
const ll LINF = LLONG_MAX >> 1;
const ll mod = 1e9+9;

struct Node {
    int l = 0, r = 0, c = 0; ll val = 0;
};
Node tree[25*MAX];
vector <int> num;
int st, d, root[MAX], sz, n, arr[MAX];
ll ans;

void expand_tree(int s, int e, int k, int pnd, int cnd) {
    tree[cnd].c = tree[pnd].c + 1;
    tree[cnd].val = tree[pnd].val + num[k];
    if(s == e) return;
    int m = s + e >> 1;
    sz++;
    if(k <= m) {
        tree[cnd].r = tree[pnd].r;
        tree[cnd].l = sz;
        expand_tree(s, m, k, tree[pnd].l, tree[cnd].l);
    }
    else {
        tree[cnd].l = tree[pnd].l;
        tree[cnd].r = sz;
        expand_tree(m+1, e, k, tree[pnd].r, tree[cnd].r);
    }
}

ll cal(int s, int e, int cnt, int pnd, int cnd) {
    if(s == e) return (ll)cnt * num[s];
    int m = s + e >> 1, rcnt = tree[tree[cnd].r].c - tree[tree[pnd].r].c;
    if(rcnt >= cnt) return cal(m+1, e, cnt, tree[pnd].r, tree[cnd].r);
    else {
        ll rval = tree[tree[cnd].r].val - tree[tree[pnd].r].val;
        return cal(s, m, cnt - rcnt, tree[pnd].l, tree[cnd].l) + rval;
    }
}

void dnc1(int s, int e, int l, int r) {
    if(s > e) return;
    int m = (s + e) >> 1;
    ll tans = -1, temp;
    int idx = l, cnt;
    for(int i = l; i <= r; i++) {
        cnt = d - i + m - min(st - m, i - st);
        cnt = min(cnt, i - m + 1);
        if(cnt < 0) continue;
        temp = cal(0, n-1, cnt, root[m-1], root[i]);
        if(temp > tans) {
            idx = i;
            tans = temp;
        }
    }
    ans = max(ans, tans);
    dnc1(s, m-1, l, idx), dnc1(m+1, e, idx, r);
}

ll findMaxAttraction() {
    if(d == 0) return 0;
    for(int i = 0; i < n; i++) {
        num.eb(arr[i]);
    }
    sort(all(num));
    for(int i = 0; i < n; i++) {
        sz++;
        root[i+1] = sz;
        int k = lower_bound(all(num), arr[i]) - num.begin();
        expand_tree(0, n-1, k, root[i], root[i+1]);
    }
    dnc1(1, st, st, n);
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> st >> d;
    st++;
    for (int i = 0 ; i < n; ++i) {
        cin >> arr[i];
    }
    cout << findMaxAttraction();
    return 0;
}
