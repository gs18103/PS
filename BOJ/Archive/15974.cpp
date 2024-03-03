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

const int MAX = 3030;
const int INF = 1e9;
const ll LINF = 9e18;

vector <pll> arr;
pll base;

ll ccw(pll a, pll b, pll c) {
    return (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
}

ll dist(pll a, pll b) {
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}

pair <int, pii> pre[2][MAX][MAX];
int dp[2][MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }
    sort(all(arr), [](pll a, pll b) {
        return a.se < b.se;
    });
    sort(next(arr.begin()), arr.end(), [](pll a, pll b) {
        return ccw(arr[0], a, b) > 0;
    });

    for(int i = 1; i < n; i++) {
        dp[1][0][i] = 1;
        vector <int> L, R;
        R.eb(0);
        for(int j = 1; ccw(arr[0], arr[j], arr[i]) > 0; j++) {
            R.eb(j);
        }
        for(int j = n - 1; ccw(arr[0], arr[i], arr[j]) > 0; j--) {
            L.eb(j);
        }
        base = arr[i];
        sort(all(R), [](int a, int b) {
            return ccw(base, arr[a], arr[b]) > 0;
        });
        sort(all(L), [](int a, int b) {
            return ccw(base, arr[a], arr[b]) > 0;
        });
        int k = -1, mxidx = 0, mx = -1;
        for(auto j : L) {
            while(k + 1 < R.size() && ccw(arr[R[k+1]], arr[i], arr[j]) > 0) {
                k++;
                if(dp[1][R[k]][i] > mx) {
                    mx = dp[1][R[k]][i];
                    mxidx = R[k];
                }
            }
            if(k < 0) continue;
            if(dp[0][i][j] < mx + 1) {
                dp[0][i][j] = mx + 1;
                pre[0][i][j] = {1, {mxidx, i}};
            }
        }

        k = R.size();
        reverse(all(L));
        mx = -1, mxidx = 0;
        for(auto j : L) {
            while(k > 0 && ccw(arr[R[k-1]], arr[i], arr[j]) < 0) {
                k--;
                if(dp[0][R[k]][i] > mx) {
                    mx = dp[0][R[k]][i];
                    mxidx = R[k];
                }
            }
            if(k == R.size()) continue;
            if(dp[1][i][j] < mx + 1) {
                dp[1][i][j] = mx + 1;
                pre[1][i][j] = {0, {mxidx, i}};
            }
        }
    }

    int mx = 0;
    pair <int, pii> pos;
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(dp[1][i][j] > mx) {
                mx = dp[1][i][j];
                pos = {1, {i, j}};
            }
        }
    }

    vector <pll> ans;
    while(pos.se.se != 0) {
        ans.eb(arr[pos.se.se]);
        pos = pre[pos.fi][pos.se.fi][pos.se.se];
    }
    ans.eb(arr[0]);
    if(ans.size() < 4) {
        cout << 0 << endl;
        return 0;
    }
    reverse(all(ans));
    cout << ans.size() << '\n';
    for(auto i : ans) {
        cout << i.fi << ' ' << i.se << '\n';
    }
}