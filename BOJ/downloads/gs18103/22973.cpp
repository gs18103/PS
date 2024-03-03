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

const int MAX = 101010;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll k;
    cin >> k;
    k = abs(k);
    if(k == 0) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < 40; i++) {
        ll bit = 1LL << i;
        if(k == bit) {
            cout << i + 1 << endl;
            return 0;
        }
        if((k / (2 * bit)) & 1) k -= bit;
        else k += bit;
        if(k % (2 * bit) != 0) {
            cout << -1 << endl;
            return 0;
        }
    }
}