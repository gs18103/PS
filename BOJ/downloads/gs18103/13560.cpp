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

const int MAX = 8080;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    ll sum = 0;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(all(v));
    if(sum != (ll)n * (n - 1) / 2) {
        cout << -1;
        return 0;
    }
    ll tsum = 0;
    sum = 0;
    for(int i = n - 1; i >= 0; i--) {
        sum += i;
        tsum += v[i];
        if(tsum > sum) {
            cout << -1;
            return 0;
        }
    }
    cout << 1;
}