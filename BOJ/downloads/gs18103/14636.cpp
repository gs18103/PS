#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 505050;
const int INF = 1e9;
const ll LINF = 1e18;

ll ans[MAX];
vector <pll> a, b;

void dnc(int s, int e, int l, int r) {
    if(s > e) return;
    int m = s + e >> 1;
    int idx = l;
    ans[m] = -LINF;
    for(int i = l; i <= r; i++) {
        ll temp = (b[m].fi - a[i].fi) * (b[m].se - a[i].se);
        if(b[m].fi < a[i].fi && temp > 0) temp = 0; 
        if(ans[m] < temp) {
            ans[m] = temp;
            idx = i;
        }
    }

    dnc(s, m-1, l, idx);
    dnc(m+1, e, idx, r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector <pll> A(m), B(n);
    for(int i = 0; i < m; i++) {
        cin >> A[i].fi >> A[i].se;
    }
    for(int i = 0; i < n; i++) {
        cin >> B[i].fi >> B[i].se;
    }

    sort(all(A));
    sort(all(B));
    for(int i = 0; i < m; i++) {
        if(a.empty() || a.back().se > A[i].se) a.eb(A[i]);
    }
    for(int i = n - 1; i >= 0; i--) {
        if(b.empty() || b.back().se < B[i].se) b.eb(B[i]);
    }
    reverse(all(b));
    dnc(0, b.size()-1, 0, a.size()-1);
    ll ANS = 0;
    for(int i = 0; i < b.size(); i++) {
        ANS = max(ANS, ans[i]);
    }
    cout << ANS;
}