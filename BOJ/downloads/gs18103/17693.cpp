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

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;
const int mod = 1e9+7;

struct containor {
    int s, e, c;
} arr[MAX];
int idx1[2*MAX], idx2[2*MAX], n;

struct SEG {
    vector <pii> tree;
    void init(int n) {
        tree.resize(4*n+10);
        for(int i = 0; i < tree.size(); i++) tree[i] = make_pair(-INF, 0);
    }
    inline void update(int node, int s, int e, int k, int val) {
        if(s == e) {
            tree[node] = make_pair(val, k);
            return;
        }
        int m = (s + e) / 2;
        if(k <= m) update(node*2, s, m, k, val);
        else update(node*2+1, m+1, e, k, val);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
    inline pii cal(int node, int s, int e, int l, int r) {
        if(s > r || e < l) return make_pair(-INF, 0);
        if(s >= l && e <= r) return tree[node];
        int m = (s + e) / 2;
        return max(cal(node*2, s, m, l, r), cal(node*2+1, m+1, e, l, r));
    }
} st1, st2;

queue <pii> q;

void bfs(int x, int c) {
    arr[x].c = c;
    pii temp;
    temp = st1.cal(1, 1, 2*n, arr[x].s+1, arr[x].e-1);
    while(temp.fi > arr[x].e) {
        int i = idx1[temp.se];
        st1.update(1, 1, 2*n, arr[i].s, -INF);
        st2.update(1, 1, 2*n, arr[i].e, -INF);
        q.em(i, 3-c);
        temp = st1.cal(1, 1, 2*n, arr[x].s+1, arr[x].e-1);
    }
    temp = st2.cal(1, 1, 2*n, arr[x].s+1, arr[x].e-1);
    while(temp.fi > -arr[x].s) {
        int i = idx2[temp.se];
        st1.update(1, 1, 2*n, arr[i].s, -INF);
        st2.update(1, 1, 2*n, arr[i].e, -INF);
        q.em(i, 3-c);
        temp = st2.cal(1, 1, 2*n, arr[x].s+1, arr[x].e-1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    st1.init(2*n), st2.init(2*n);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].s >> arr[i].e;
        st1.update(1, 1, 2*n, arr[i].s, arr[i].e);
        st2.update(1, 1, 2*n, arr[i].e, -arr[i].s);
        idx1[arr[i].s] = idx2[arr[i].e] = i;
    }

    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if(arr[i].c == 0) {
            st1.update(1, 1, 2*n, arr[i].s, -INF);
            st2.update(1, 1, 2*n, arr[i].e, -INF);
            q.em(i, 1);
            while(!q.empty()) {
                int x = q.front().fi, c = q.front().se;
                q.pop();
                bfs(x, c);
            }
            ans = (ans * 2) % mod;
        }
    }
    
    sort(arr+1, arr+n+1, [](containor a, containor b) {
        return a.s < b.s;
    });
    for(int i = 1; i <= n; i++) {
        pii c1 = st1.cal(1, 1, 2*n, arr[i].s, arr[i].e);
        pii c2 = st2.cal(1, 1, 2*n, arr[i].s, arr[i].e);
        if(c1.fi != -INF && (c1.fi == arr[i].c || c2.fi == -arr[i].c)) {
            return !(cout << 0);
        }
        st1.update(1, 1, 2*n, arr[i].e, arr[i].c);
        st2.update(1, 1, 2*n, arr[i].e, -arr[i].c);
    }
    cout << ans;
}