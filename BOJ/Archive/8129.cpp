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
const int INF = (1 << 30) - 1;
const ll LINF = 1LL << 60;

pii arr[606];
int val[2][606][606], idx;
pair <pii, int> p[10101];

int ccw(pii a, pii b, pii c) {
    return (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, sum = 0, ans = -INF;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> p[i].fi.fi >> p[i].fi.se >> p[i].se;
        sum += p[i].se;
    }

    for(int i = 1; i <= n; i++) {
        int cal = 0;
        idx = i;
        sort(p+1, p+m+1, [](pair <pii, int> a, pair <pii, int> b) {
            return ccw(arr[idx], a.fi, b.fi) < 0;
        });
        idx = 1;
        for(int j = i + 1; j <= n; j++) {
            int temp = 0;
            while(idx <= m && ccw(arr[i], arr[j], p[idx].fi) >= 0) {
                if(ccw(arr[i], arr[j], p[idx].fi) == 0) temp += p[idx].se;
                cal += p[idx].se;
                idx++;
            }
            val[0][i][j] = cal - temp;
            val[1][i][j] = sum - cal;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                ans = max(ans, sum - val[0][i][j] - val[0][j][k] - val[1][i][k]);
            }
        }
    }
    cout << ans;
}