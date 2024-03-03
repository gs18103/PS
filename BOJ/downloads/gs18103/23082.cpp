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

int d[30];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    if(n == 0) return cout << 0, 0;
    int x = 1;
    if(n < 0) n = -n, x = -1;
    for(int i = 0; n; n /= 3, i++) {
        if(n % 3 == 1) d[i] += x;
        if(n % 3 == 2) d[i] -= x, d[i+1] += x;
    }
    for(int i = 0; i < 30; i++) {
        if(d[i] * x >= 2) d[i] -= 3 * x, d[i+1] += x;
    }
    bool flag = false;
    for(int i = 29; i >= 0; i--) {
        if(d[i] != 0) flag = true;
        if(flag) {
            if(d[i] == -1) cout << "T";
            else cout << d[i];
        }
    }
}