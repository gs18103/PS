#include <bits/stdc++.h>

using namespace std;

int sum[1010101];
int cnt[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    cnt[0] = 1;
    for(int i = 1; i <= n; i++) {
        int u; cin >> u;
        u %= m;
        sum[i] = (sum[i-1] + u) % m;
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    cout << ans;
}