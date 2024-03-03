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

const int MAX = 101010;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <pii> A(n+m+1);
    vector <ll> dp(n+m+1), s(n+m+1);
    for(int i = 1; i <= n; i++) {
        cin >> A[i].fi;
    }
    for(int i = 1; i <= m; i++) {
        cin >> A[n+i].fi;
        A[n+i].se = 1;
    }
    sort(next(A.begin()), A.end());
    A[0] = {-INF, 1-A[1].se};
    for(int i = 1; i <= n + m; i++) {
        s[i] = s[i-1] + A[i].fi;
    }

    int p = 1, N = n + m;
    for(int i = 1; i <= N; i++) {
        int j = i;
        while(j < N && A[j+1].se == A[i].se) j++;
        for(int k = p; k < i; k++) {
            dp[k] = min(dp[k], dp[k-1] + A[i].fi - A[k].fi);
        }
        ll a = 0, b = dp[i-1];
        for(int k = i; k <= j; k++) {
            a += A[k].fi - A[i-1].fi;
            int x = 2 * i - k - 1;
            if(x >= p) {
                b = min(b, dp[x-1] + (ll)A[i-1].fi * (i - x) - s[i-1] + s[x-1]);
            }
            dp[k] = a + b;
        }
        p = i;
        i = j;
    }
    cout << dp[N] << endl;
}