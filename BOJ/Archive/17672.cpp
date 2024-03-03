#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define my_assert cout << "!" << endl;

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 1110101;
const int INF = (1 << 30) - 1;
const ll LINF = 1LL << 60;

int n, m;
ll A[MAX], S[MAX], P[MAX];
ll B[MAX], T[MAX], Q[MAX];
ll sumA[MAX], sumB[MAX], ans;
ll tree[8*MAX], lazy1[8*MAX];
int lazy2[8*MAX];

inline void update_lazy(int node, int s, int e) {
    tree[node] = tree[node] * lazy2[node] + lazy1[node];
    if(s != e) {
        if(lazy2[node] == 1) {
            lazy1[node*2] += lazy1[node];
            lazy1[node*2+1] += lazy1[node];
        }
        else {
            lazy1[node*2] = lazy1[node], lazy2[node*2] = 0;
            lazy1[node*2+1] = lazy1[node], lazy2[node*2+1] = 0;
        }
    }
    lazy1[node] = 0;
    lazy2[node] = 1;
}

inline void update1(int node, int s, int e, int r, ll val) {
    update_lazy(node, s, e);
    if(s > r) return;
    if(e <= r) {
        lazy1[node] += val;
        update_lazy(node, s, e);
        return;
    }
    int mi = (s + e) / 2;
    update1(node*2, s, mi, r, val);
    update1(node*2+1, mi+1, e, r, val);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

inline void update2(int node, int s, int e, int l, int r, ll a, ll b) {
    update_lazy(node, s, e);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        lazy2[node] = a;
        lazy1[node] = b;
        update_lazy(node, s, e);
        return;
    }
    int mi = (s + e) / 2;
    update2(node*2, s, mi, l, r, a, b);
    update2(node*2+1, mi+1, e, l, r, a, b);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

inline ll cal(int node, int s, int e, int l, int r) {
    update_lazy(node, s, e);
    if(s > r || e < l) return -LINF;
    if(s >= l && e <= r) return tree[node];
    int mi = (s + e) / 2;
    return max(cal(node*2, s, mi, l, r), cal(node*2+1, mi+1, e, l, r));
}

inline int get(int node, int s, int e, ll val) {
    update_lazy(node, s, e);
    if(s == e) return s;
    update_lazy(node*2, s, e);
    if(tree[node*2] > val) return get(node*2, s, (s+e)/2, val);
    else return get(node*2+1, (s+e)/2+1, e, val);
}

struct point {
    int x, y; ll val;
    point(int x, int y, ll val) : x(x), y(y), val(val) {}
};
vector <point> po;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i = 1; i < 4 * MAX; i++) lazy2[i] = 1;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> A[i] >> S[i] >> P[i];
        sumA[i] = sumA[i-1] + A[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> B[i] >> T[i] >> Q[i];
        sumB[i] = sumB[i-1] + B[i];
        ans += Q[i];
    }
    for(int i = 1; i <= n; i++) {
        int temp = upper_bound(sumB, sumB+m+1, S[i] - sumA[i]) - sumB - 1;
        if(temp >= 0) po.eb(i, temp, P[i]);
    }
    for(int i = 1; i <= m; i++) {
        int temp = upper_bound(sumA, sumA+n+1, T[i] - sumB[i]) - sumA - 1;
        if(temp < 0) ans -= Q[i];
        else if(temp < n) po.eb(temp+1, i-1, -Q[i]);
    }
    sort(all(po), [](point a, point b) {
        if(a.x == b.x) return a.y > b.y;
        return a.x < b.x;
    });

    ll rem = 0;
    for(int i = 0; i < po.size(); i++) {
        if(i+1 < po.size() && po[i].x == po[i+1].x && po[i].y == po[i+1].y) {
            rem += po[i].val;
            continue;
        }
        update1(1, 0, m, po[i].y, po[i].val + rem);
        ll temp = cal(1, 0, m, 0, po[i].y);
        int idx = m + 1;
        if(cal(1, 0, m, 0, m) > temp) idx = get(1, 0, m, temp);
        update2(1, 0, m, po[i].y+1, idx - 1, 0, temp);
        rem = 0;
    }
    cout << cal(1, 0, m, m, m) + ans;
}
