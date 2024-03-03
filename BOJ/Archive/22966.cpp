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

pair <int, string> a[4];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].se >> a[i].fi;
    }
    sort(a, a+n);
    cout << a[0].se << endl;
}