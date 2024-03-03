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
    vector <ll> a(n+1), sum(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ll tsum;
            if(i <= j) tsum = sum[j] - sum[i-1];
            else tsum = sum[n] - sum[i-1] + sum[j];
            if(tsum < 0) ans += (-tsum + sum[n] - 1) / sum[n];
        }
    }
    cout << ans;
}