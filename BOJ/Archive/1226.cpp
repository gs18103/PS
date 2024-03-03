#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define em emplace

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int INF = 1 << 30;
const ll LINF = 1LL << 62;
const int MAX = 303;

pii arr[MAX];
int dp[2][101010], chk[MAX][101010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].fi;
        sum += arr[i].fi;
        arr[i].se = i;
    }
    sort(arr+1, arr+n+1);
    reverse(arr+1, arr+n+1);

    dp[1][arr[1].fi] = arr[1].fi;
    chk[1][arr[1].fi] = 1;
    dp[1][0] = -1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= sum; j++) dp[i%2][j] = 0;
        dp[i%2][0] = -1;
        for(int j = 0; j <= sum; j++) {
            if(j + arr[i].fi <= sum && dp[(i+1)%2][j] != 0) {
                dp[i%2][j+arr[i].fi] = max(dp[i%2][j+arr[i].fi], arr[i].fi);
                if(dp[i%2][j+arr[i].fi] == arr[i].fi) chk[i][j+arr[i].fi] = 1;
            }
            dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][j]);
            if(dp[i%2][j] == dp[(i+1)%2][j]) chk[i][j] = 0;
        }
    }
    for(int i = sum; i > sum / 2; i--) {
        if(i - dp[n%2][i] <= sum / 2) {
            vector <int> ans;
            for(int j = n; j >= 1; j--) {
                if(chk[j][i]) {
                    ans.eb(arr[j].se);
                    i -= arr[j].fi;
                }
            }
            sort(all(ans));
            cout << ans.size() << endl;
            for(auto i : ans) cout << i << ' ';
            return 0;
        }
    }
}