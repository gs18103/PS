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

ll nC2(ll x) {
    return x * (x - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    if(k > nC2(n)) return !(cout << "-1");

    ll lb = 0, ub = n, l, r;
    while(lb < ub) {
        ll m = (lb + ub + 1) >> 1;
        if(nC2(m) <= k) lb = m;
        else ub = m - 1;
    }
    r = lb;
    lb = 0, ub = n;
    while(lb < ub) {
        ll m = (lb + ub) >> 1;
        if(nC2(n) - nC2(n - m) < k) lb = m + 1;
        else ub = m;
    }
    l = lb;
    cout << max(nC2(r) + nC2(n - r), nC2(l) + nC2(n - l));
}