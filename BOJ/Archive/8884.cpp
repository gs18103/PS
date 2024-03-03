#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 505;
const int INF = 1e9;
const ll LINF = 1e18;

int a[MAX];
int dp[MAX][MAX], mn[MAX][MAX], mx[MAX][MAX], cnt[MAX], dp2[MAX], sum[MAX][MAX];
bool chk[MAX][MAX];

int cost(int s, int m, int e) {
    int x = max(mn[s][m], mn[m+1][e]);
    return e - s + 1 - sum[e][x-1] + sum[s-1][x-1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        mx[i][i] = mn[i][i] = a[i];
        sum[i][a[i]]++;
        if(a[i] > n) {
            cout << "impossible";
            return 0;
        }
        for(int j = 1; j <= n; j++) cnt[j] = 0;
        bool flag = false;
        cnt[a[i]] = 1;
        for(int j = i + 1; j <= n; j++) {
            mx[i][j] = max(mx[i][j-1], a[j]);
            mn[i][j] = min(mn[i][j-1], a[j]);
            dp[i][j] = INF;
            if(cnt[a[j]]) flag = true;
            chk[i][j] = flag;
            cnt[a[j]]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    for(int k = 1; k < n; k++) {
        for(int i = 1; i + k <= n; i++) {
            if(chk[i][i+k]) continue;
            for(int j = 0; j < k; j++) {
                dp[i][i+k] = min(dp[i][i+k], dp[i][i+j] + dp[i+j+1][i+k] + cost(i, i+j, i+k));
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        dp2[i] = INF;
        for(int j = 0; j < i; j++) {
            if(dp[j+1][i] == INF) continue;
            if(mx[j+1][i] != i - j) continue;
            dp2[i] = min(dp2[i], dp2[j] + dp[j+1][i]);
        }
    }
    if(dp2[n] == INF) cout << "impossible";
    else cout << dp2[n];
}