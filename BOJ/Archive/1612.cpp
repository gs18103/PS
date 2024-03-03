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
    if(n % 2 == 0 || n % 5 == 0) return cout << -1, 0;
    int ans = 1, x;
    if(n % 10 == 1) x = n / 10;
    if(n % 10 == 3) x = (n * 7) / 10;
    if(n % 10 == 7) x = (n * 3) / 10;
    if(n % 10 == 9) x = (n * 9) / 10;
    while(x) {
        while(x % 10 != 1) x += n;
        x /= 10;
        ans++;
    }
    cout << ans;
}