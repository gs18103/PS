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
const ll mod = 1e9+7;

ll dnc(int s, int e, vector <int> &a) {
    if(s == e) return 0;
    int m = s + e >> 1;
    ll ans = 0;
    ans += dnc(s, m, a) + dnc(m+1, e, a);

    vector <int> tmp;
    for(int i = m + 1; i <= e; i++) tmp.eb(a[i]);
    sort(all(tmp));
    for(int i = s; i <= m; i++) {
        ans += lower_bound(all(tmp), a[i]) - tmp.begin();
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << dnc(0, n-1, a);
}