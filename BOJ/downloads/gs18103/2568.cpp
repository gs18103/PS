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

const int MAX = 4040404;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector <pii> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i].fi >> A[i].se;
    }
    
    sort(all(A));
    vector <int> p(n, -1);
    vector <bool> chk(n);
    vector <pii> v;
    v.eb(A[0].se, 0);
    for(int i = 1; i < n; i++) {
        int idx = lower_bound(all(v), pii(A[i].se, i)) - v.begin();
        if(idx == v.size()) v.eb(A[i].se, i);
        else v[idx] = {A[i].se, i};
        if(idx > 0) p[i] = v[idx-1].se;
    }
    int idx = v[v.size()-1].se;
    while(idx >= 0) {
        chk[idx] = true;
        idx = p[idx];
    }
    cout << n - v.size() << '\n';
    for(int i = 0; i < n; i++) {
        if(chk[i]) continue;
        cout << A[i].fi << '\n';
    }
}
