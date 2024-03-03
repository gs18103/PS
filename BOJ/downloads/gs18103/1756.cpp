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

const int MAX = 303030;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

int arr[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int d, n;
    cin >> d >> n;
    for(int i = 1; i <= d; i++) {
        cin >> arr[i];
        if(i > 1) arr[i] = min(arr[i], arr[i-1]);
    }
    reverse(arr+1, arr+d+1);
    int idx = 0;
    for(int i = 1; i <= n; i++) {
        int u; cin >> u;
        int nid = lower_bound(arr+idx+1, arr+d+1, u) - arr;
        idx = max(idx+1, nid);
    }
    if(idx > d + 1) cout << 0;
    else cout << d - idx + 1;
}