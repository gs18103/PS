#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int sum[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while(n != 0 && m != 0) {
        for(int i = 1; i <= n; i++) sum[i] = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                int u; cin >> u;
                sum[j] += u;
            }
        }
        int mx = 0;
        for(int i = 1; i <= n; i++) {
            mx = max(mx, sum[i]);
        }
        cout << mx << '\n';
        cin >> n >> m;
    }
}