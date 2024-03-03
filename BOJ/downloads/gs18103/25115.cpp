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
    
    int n;
    cin >> n;
    vector <ll> P(n+1), sum(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> P[i];
        sum[i] = sum[i-1] + P[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(sum[i] / 10 >= sum[n] - sum[i]) {
            ll X = min((11 * sum[i] - 10 * sum[n]) / 11, sum[i-1] / 10);
            ans += P[i] - X;
            break;
        }
        ans += P[i];
    }
    cout << ans;
}