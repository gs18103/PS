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

const int MAX = 1010;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

int n, Lx, Ly, dp[20202];
struct box {
    int lx, ly, lz, px, py;
} arr[20202];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> Lx >> Ly >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].lx >> arr[i].ly >> arr[i].lz >> arr[i].px >> arr[i].py;
        dp[i] = arr[i].lz;
        for(int j = i - 1; j >= 1; j--) {
            if(arr[i].px+1 > arr[j].px+arr[j].lx) continue;
            if(arr[i].px+arr[i].lx < arr[j].px+1) continue;
            if(arr[i].py+1 > arr[j].py+arr[j].ly) continue;
            if(arr[i].py+arr[i].ly < arr[j].py+1) continue;
            dp[i] = max(dp[i], dp[j] + arr[i].lz);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}