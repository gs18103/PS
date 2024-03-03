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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 10101;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> get_fail(vector <int> &v) {
    int p = 0, n = v.size();
    vector <int> F(n);
    for(int i = 1; i < n; i++) {
        while(p && v[p] != v[i]) p = F[p-1];
        if(v[p] == v[i]) p++;
        F[i] = p;
    }
    return F;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = n - 1; i >= 0; i--) {
        cin >> a[i];
    }
    vector <int> F = get_fail(a);

    int mx = 0, cnt = 0;
    for(int i = 1; i < n; i++) {
        if(F[i] > mx) {
            mx = F[i];
            cnt = 0;
        }
        if(F[i] == mx) cnt++;
    }
    if(mx == 0) cout << -1;
    else cout << mx << ' ' << cnt;
}