#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define em emplace

using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1 << 30;
const ll LINF = 1LL << 62;

struct point {
    ll x, y;
    point() : x(0), y(0) {} ;
    point(int X, int Y) : x(X), y(Y) {} ;
    point operator - (point P) {
        return point(x-P.x, y-P.y);
    }
} arr[MAX];

bool cmp(const point& a, const point& b) {
    return a.y * b.x < b.y * a.x;
}

vector <point> tree[4*MAX], ch[4*MAX];

void init(int node, int s, int e) {
    if(s == e) {
        ch[node].eb(arr[s]);
        return;
    }
    int m = (s + e) >> 1;
    init(node*2, s, m), init(node*2+1, m+1, e);

    for(int i = s; i <= e; i++) tree[node].eb(arr[i]);
    sort(all(tree[node]), [](point a, point b) {
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });
    ch[node].eb(tree[node][0]);
    for(int i = 1; i < tree[node].size(); i++) {
        while(ch[node].size() >= 2) {
            point p1 = ch[node][ch[node].size()-2];
            point p2 = ch[node][ch[node].size()-1];
            if(cmp(p2-p1, tree[node][i]-p1)) break;
            ch[node].pop_back();
        }
        ch[node].eb(tree[node][i]);
    }
}

bool solve(int node, int s, int e, int l, int r, point p1, point p2) {
    if(s > r || e < l) return false;
    if(s >= l && e <= r) {
        if(p1.x == p2.x) {
            if(tree[node][0].x < p1.x) return true;
            else return false;
        }
        int lb = 0, ub = ch[node].size() - 2;
        while(lb < ub) {
            int m = (lb + ub) >> 1;
            if(cmp(p1-p2, ch[node][m+1]-ch[node][m])) ub = m;
            else lb = m+1;
        }
        for(int i = max(0, lb-1); i <= min((int)ch[node].size()-1, lb+1); i++) {
            point p = ch[node][i];
            if((double)p.y < (double)(p1.y-p2.y)/(p1.x-p2.x)*(p.x-p1.x)+p1.y) {
                return true;
            }
        }
        return false;
    }
    int m = (s + e) >> 1;
    return solve(node*2, s, m, l, r, p1, p2) || solve(node*2+1, m+1, e, l, r, p1, p2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr+1, arr+n+1, cmp);
    init(1, 1, n);
    for(int i = 1; i <= m; i++) {
        point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        if(p1.y * p2.x > p2.y * p1.x) swap(p1, p2);
        int l = (int)(upper_bound(arr+1, arr+n+1, p1, cmp)-arr);
        int r = (int)(lower_bound(arr+1, arr+n+1, p2, cmp)-arr-1);
        if(l > r) {
            cout << "N\n";
            continue;
        }
        if(solve(1, 1, n, l, r, p1, p2)) cout << "Y\n";
        else cout << "N\n";
    }
}