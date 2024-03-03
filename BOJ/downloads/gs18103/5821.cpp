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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

ll X[MAX], sum[MAX];

ll cal(int l, int r) {
    int m = l + r >> 1;
    return sum[r] - sum[m] - X[m] * (r - m) + X[m] * (m - l) - (sum[m-1] - sum[l-1]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, L;
    ll B;
    cin >> n >> L >> B;
    for(int i = 1; i <= n; i++) {
        cin >> X[i];
        sum[i] = sum[i-1] + X[i];
    }

    int p = 1, ans = 1;
    for(int i = 1; i <= n; i++) {
        while(cal(p, i) > B) p++;
        ans = max(ans, i - p + 1);
    }
    cout << ans;
}