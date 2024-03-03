#include <bits/stdc++.h>
#define em emplace
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1 << 30;
const ll LINF = 1LL << 62;

int arr[MAX];
ll ans;
bool chk[MAX];
vector <int> num;

struct SEG {
    vector <int> tree, lazy;

    void init(int n) {
        tree.resize(4*n+10), lazy.resize(4*n+10);
        for(int i = 0; i < tree.size(); i++) tree[i] = -INF, lazy[i] = 0;
    }

    void update_lazy(int node, int s, int e) {
        tree[node] += lazy[node];
        if(s != e) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update_range(int node, int s, int e, int l, int r, int diff) {
        update_lazy(node, s, e);
        if(s > r || e < l) return;
        if(s >= l && e <= r) {
            tree[node] += diff;
            if(s != e) {
                lazy[node<<1] += diff;
                lazy[node<<1|1] += diff;
            }
            return;
        }
        int m = (s + e) >> 1;
        update_range(node<<1, s, m, l, r, diff);
        update_range(node<<1|1, m+1, e, l, r, diff);
        tree[node] = max(tree[node<<1], tree[node<<1|1]);
    }

    int cal(int node, int s, int e, int l, int r) {
        update_lazy(node, s, e);
        if(s > r || e < l) return -INF;
        if(s >= l && e <= r) return tree[node];
        int m = (s + e) >> 1;
        return max(cal(node<<1, s, m, l, r), cal(node<<1|1, m+1, e, l, r));
    }
} st;

struct BIT {
    vector <int> tree;
    void update(int i, int diff) {
        while(i < tree.size()) {
            tree[i] += diff;
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
} ft;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        num.eb(arr[i]);
    }
    sort(all(num));
    for(int i = 1; i <= n; i++) {
        arr[i] = lower_bound(all(num), arr[i]) - num.begin() + 1;
    }
    ft.tree.resize(n+10);
    for(int i = n; i >= 1; i--) {
        ans += ft.cal(arr[i]-1);
        ft.update(arr[i], 1);
    }

    st.init(n);
    vector <pii> X, Y;
    X.eb(arr[1], 1), Y.eb(arr[n], n);
    chk[1] = true;
    for(int i = 2; i <= n; i++) {
        if(arr[i] > X.back().fi) X.eb(arr[i], i), chk[i] = true;
    }
    for(int i = n-1; i > 0; i--) {
        if(arr[i] < Y.back().fi && !chk[i]) Y.eb(arr[i], i);
    }
    X.eb(INF, n + 1);
    reverse(all(Y));
    if(chk[n]) Y.pop_back();

    priority_queue <pii, vector <pii>, greater <pii> > pq;
    queue <pii> del;
    int M = -1, idx = 0;
    for(int i = 1; i <= n; i++) {
        if(chk[i]) st.update_range(1, 1, n, i, i, INF + 1);
        else if(!Y.empty() && Y[idx].se == i) {
            while(!pq.empty() && pq.top().fi < arr[i]) {
                pii temp = pq.top();
                pq.pop();
                int s = upper_bound(all(X), make_pair(temp.fi, n))->se;
                int ts = lower_bound(all(X), make_pair(arr[i], 0))->se;
                if(s <= n) st.update_range(1, 1, n, s, temp.se, -2);
                if(ts < s) st.update_range(1, 1, n, ts, s-1, -1);
            }
            while(!pq.empty() && pq.top().fi == arr[i]) {
                pii temp = pq.top();
                pq.pop();
                int s = upper_bound(all(X), make_pair(temp.fi, n))->se;
                int ts = lower_bound(all(X), make_pair(arr[i], 0))->se;
                if(s <= n) st.update_range(1, 1, n, s, temp.se, -1);
                if(ts < s) st.update_range(1, 1, n, ts, s-1, -1);
                del.em(temp);
            }
            int s = lower_bound(all(X), make_pair(arr[i], 0))->se;
            if(arr[s] == arr[i]) st.update_range(1, 1, n, s, s, -1);
            M = max(M, st.cal(1, 1, n, s, i));
            idx++;
            while(!del.empty()) {
                pii temp = del.front();
                del.pop();
                int s = upper_bound(all(X), make_pair(temp.fi, n))->se;
                if(s <= n) st.update_range(1, 1, n, s, temp.se, -1);
            }
        }
        else {
            int s = upper_bound(all(X), make_pair(arr[i], n))->se;
            int ts = lower_bound(all(X), make_pair(arr[i], 0))->se;
            if(s <= n) st.update_range(1, 1, n, s, i, 2);
            if(ts < s) st.update_range(1, 1, n, ts, s-1, 1);
            pq.em(arr[i], i);
        }
    }
    cout << ans - M;
}