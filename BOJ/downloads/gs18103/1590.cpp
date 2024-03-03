#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, T;
    cin >> n >> T;
    vector <int> v;
    for(int i = 1; i <= n; i++) {
        int s, l, c;
        cin >> s >> l >> c;
        for(int j = 0; j < c; j++) v.eb(s + l * j);
    }
    sort(all(v));
    if(v.back() < T) cout << -1;
    else cout << *lower_bound(all(v), T) - T;
}