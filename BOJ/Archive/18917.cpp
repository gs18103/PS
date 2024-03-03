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
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;
    ll sum = 0;
    int X = 0;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            sum += x;
            X ^= x;
        }
        if(t == 2) {
            int x;
            cin >> x;
            sum -= x;
            X ^= x;
        }
        if(t == 3) cout << sum << '\n';
        if(t == 4) cout << X << '\n';
    }
}