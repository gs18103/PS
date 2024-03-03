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

const int INF = 1 << 30;
const ll LINF = 1LL << 62;
const int MAX = 101010;

ll h[MAX], sum[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; ll T;
    cin >> n >> T;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        sum[i] = sum[i-1] + h[i];
    }

    ll ans = 0;
    for(int i = 1; i < n; i++) {
        if(T / 2 - i + 1 < 0) break;
        ans = max(ans, (h[i] + h[i+1]) * (T / 2 - i + 1) + sum[i-1] + sum[i]);
    }
    cout << ans << endl;
}