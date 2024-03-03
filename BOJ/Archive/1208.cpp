#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map <int, int> mp1, mp2;
    int n1 = n / 2, n2 = (n + 1) / 2;
    for(int i = 0; i < (1 << n1); i++) {
        int tsum = 0;
        for(int j = 0; j < n1; j++) {
            if(i >> j & 1) tsum += a[j];
        }
        mp1[tsum]++;
    }
    for(int i = 0; i < (1 << n2); i++) {
        int tsum = 0;
        for(int j = 0; j < n2; j++) {
            if(i >> j & 1) tsum += a[j+n1];
        }
        mp2[tsum]++;
    }

    auto it = prev(mp2.end());
    ll ans = 0;
    for(auto i : mp1) {
        while(it != mp2.begin() && it->fi + i.fi > s) it = prev(it);
        if(it->fi + i.fi == s) ans += (ll)it->se * i.se;
    }
    if(s == 0) ans--;
    cout << ans;
}