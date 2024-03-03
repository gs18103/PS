#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 2020;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

bool get(int s, int e, vector <int> &L, vector <int> &R) {
    if(s > e) return false;
    int l = s, r = e;
    while(l <= r) {
        if(R[l] > e && L[l] < s) {
            return get(s, l-1, L, R) || get(l+1, e, L, R);
        }
        if(R[r] > e && L[r] < s) {
            return get(s, r-1, L, R) || get(r+1, e, L, R);
        }
        l++;
        r--;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    map <int, int> mp;
    vector <int> R(n), L(n), A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < n; i++) {
        if(mp.find(A[i]) == mp.end()) {
            mp[A[i]] = i;
            L[i] = -1;
        }
        else {
            L[i] = mp[A[i]];
            mp[A[i]] = i;
        }
    }
    mp.clear();
    for(int i = n - 1; i >= 0; i--) {
        if(mp.find(A[i]) == mp.end()) {
            mp[A[i]] = i;
            R[i] = n;
        }
        else {
            R[i] = mp[A[i]];
            mp[A[i]] = i;
        }
    }
    if(get(0, n-1, L, R)) cout << "boring\n";
    else cout << "non-boring\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}