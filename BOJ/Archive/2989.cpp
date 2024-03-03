#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

struct point {
    int x, y, f;
} arr[303030];

int ord[303030], xmx[101010], ymx[101010], pre[303030], dp[303030];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].f;
        ord[i] = i;
    }
    sort(ord+1, ord+n+1, [](int a, int b) {
        if(arr[a].x == arr[b].x) return arr[a].y < arr[b].y;
        return arr[a].x < arr[b].x;
    });

    dp[1] = -INF;
    for(int i = 1; i <= n; i++) {
        int u = ord[i];
        dp[u] = -INF;
        if(u == 1) dp[u] = arr[u].f;

        int &xx = xmx[arr[u].x], &yy = ymx[arr[u].y];
        if(dp[xx] >= k && dp[u] < dp[xx] + arr[u].f - k) {
            dp[u] = dp[xx] + arr[u].f - k;
            pre[u] = xx;
        }
        if(dp[yy] >= k && dp[u] < dp[yy] + arr[u].f - k) {
            dp[u] = dp[yy] + arr[u].f - k;
            pre[u] = yy;
        }
        if(dp[u] > dp[xx]) xx = u;
        if(dp[u] > dp[yy]) yy = u;
    }

    stack <int> ans;
    for(int cur = n; cur != 1; cur = pre[cur]) {
        ans.emplace(cur);
    }
    ans.emplace(1);

    cout << dp[n] << '\n' << ans.size() << '\n';
    while(!ans.empty()) {
        cout << arr[ans.top()].x << ' ' << arr[ans.top()].y << '\n';
        ans.pop();
    }
}