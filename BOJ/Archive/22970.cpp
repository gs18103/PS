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

const int MAX = 1010101;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const ll mod = 998244353;

int a[5050];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    int cnt = 0, ans = 1;
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        bool flag = false;
        for(int j = i + 1; j <= n; j++) {
            if(a[j] == a[j-1]) {
                ans = max(ans, j - i);
                break;
            }
            if(a[j] > a[j-1] && flag) {
                ans = max(ans, j - i);
                break;
            }
            if(a[j] < a[j-1] && !flag) {
                flag = true;
            }
            if(j == n) ans = max(ans, n - i + 1);
        }
    }
    cout << ans << '\n';
}