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
    vector <ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ll u;
            cin >> u;
            a[i] += u;
        }
        sum += a[i];
    }
    sum /= 2;
    sort(all(a));
    for(int i = 0; i < n / 2; i++) sum -= a[i];
    cout << sum;
}