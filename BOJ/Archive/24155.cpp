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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> a(n), num;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        num.eb(a[i]);
    }
    sort(all(num));
    for(int i = 0; i < n; i++) {
        cout << num.end() - upper_bound(all(num), a[i]) + 1 << '\n';
    }
}