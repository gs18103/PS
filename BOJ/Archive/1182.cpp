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

    int ans = 0;
    for(int i = 1; i < (1 << n); i++) {
        int tsum = 0;
        for(int j = 0; j < n; j++) {
            if(i >> j & 1) tsum += a[j];
        }
        if(tsum == s) ans++;
    }
    cout << ans;
}