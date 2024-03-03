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

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

int p[20][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[0][i];
    }
    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) {
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int k, x;
        cin >> k >> x;
        for(int i = 0; i < 20; i++) {
            if(k >> i & 1) x = p[i][x];
        }
        cout << x << '\n';
    }
}