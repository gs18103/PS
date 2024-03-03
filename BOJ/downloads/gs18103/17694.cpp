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
const int INF = 1e9;
const ll LINF = 1e18;

int n, k;
ll T, X[MAX], L[MAX], R[MAX];
pll Lmx[MAX], Lmn[MAX], Rmx[MAX], Rmn[MAX];

bool chk(ll v) {
    L[0] = R[0] = X[k];
    for(int i = k - 1; i >= 1; i--) {
        R[k-i] = X[i] + 2 * v * T * (k - i);
    }
    for(int i = k + 1; i <= n; i++) {
        L[i-k] = X[i] + 2 * v * T * (k - i);
    }

    Lmx[0] = Lmn[0] = Rmx[0] = Rmn[0] = {X[k], 0};
    for(int i = k - 1; i >= 1; i--) {
        Rmx[k-i] = max(Rmx[k-i-1], {R[k-i], k - i});
        Rmn[k-i] = min(Rmn[k-i-1], {R[k-i], k - i});
    }
    for(int i = k + 1; i <= n; i++) {
        Lmx[i-k] = max(Lmx[i-k-1], {L[i-k], i - k});
        Lmn[i-k] = min(Lmn[i-k-1], {L[i-k], i - k});
    }

    if(Lmx[n-k].fi > Rmx[k-1].fi || Lmn[n-k].fi > Rmn[k-1].fi) return false;
    
    int l = Lmn[n-k].se, r = Rmx[k-1].se;
    while(l && r) {
        if(Lmn[l-1].fi <= Rmn[r-1].fi) l = Lmn[l-1].se;
        else if(Lmx[l-1].fi <= Rmx[r-1].fi) r = Rmx[r-1].se;
        else return false;
    }
    
    Lmx[n-k] = Lmn[n-k] = {L[n-k], n-k}, Rmx[k-1] = Rmn[k-1] = {R[k-1], k-1};
    for(int i = 2; i <= k; i++) {
        Rmx[k-i] = max(Rmx[k-i+1], {R[k-i], k - i});
        Rmn[k-i] = min(Rmn[k-i+1], {R[k-i], k - i});
    }
    for(int i = n - 1; i >= k; i--) {
        Lmx[i-k] = max(Lmx[i-k+1], {L[i-k], i - k});
        Lmn[i-k] = min(Lmn[i-k+1], {L[i-k], i - k});
    }

    l = Lmn[0].se, r = Rmx[0].se;
    while(l < n - k && r < k - 1) {
        if(Lmn[l+1].fi <= Rmn[r+1].fi) l = Lmn[l+1].se;
        else if(Lmx[l+1].fi <= Rmx[r+1].fi) r = Rmx[r+1].se;
        else return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k >> T;
    for(int i = 1; i <= n; i++) {
        cin >> X[i];
    }

    ll lb = 0, ub = (INF + T - 1) / T;
    while(lb < ub) {
        ll m = lb + ub >> 1;
        if(chk(m)) ub = m;
        else lb = m + 1;
    }
    cout << lb;
}