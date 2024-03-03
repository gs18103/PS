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
const ll mod = 1e9+7;

ll dp[2][MAX][MAX], sum[2][MAX][MAX], C[MAX][MAX];
int a[MAX], b[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int L, n, m;
    cin >> L;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        b[i] += b[i-1];
    }
    int i1 = 1, i2 = 1;
    int ans = 0;

    vector <pii> cnt;
    int tcnt = 0, type;
    bool flag = false;
    while(i1 <= n && i2 <= m) {
        if(a[i1] == b[i2]) {
            i1++, i2++;
            if(flag) {
                cnt.eb(type, tcnt);
                flag = false;
                tcnt = 0;
            }
        }
        else if(a[i1] < b[i2]) {
            ans++, i1++;
            if(flag) tcnt++;
            else {
                flag = true;
                type = 0;
                tcnt = 1;
            }
        }
        else {
            ans++, i2++;
            if(flag) tcnt++;
            else {
                flag = true;
                type = 1;
                tcnt = 1;
            }
        }
    }

    C[0][0] = 1;
    for(int i = 1; i <= L; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }

    dp[0][1][1] = 1;
    sum[0][1][1] = 1;
    for(int i = 2; i <= L; i++) {
        for(int j = 1; j <= i; j++) {
            if(i & 1) dp[0][i][j] = sum[0][i-1][j-1];
            else dp[0][i][j] = sum[0][i-1][i-1] - sum[0][i-1][j-1];
            dp[0][i][j] = ((dp[0][i][j] % mod) + mod) % mod;
        }
        for(int j = 1; j <= i; j++) {
            sum[0][i][j] = sum[0][i][j-1] + dp[0][i][j];
            sum[0][i][j] %= mod;
        }
    }    
    
    dp[1][1][1] = 1;
    sum[1][1][1] = 1;
    for(int i = 2; i <= L; i++) {
        for(int j = 1; j <= i; j++) {
            if(i & 1) dp[1][i][j] = sum[1][i-1][i-1] - sum[1][i-1][j-1];
            else dp[1][i][j] = sum[1][i-1][j-1];
            dp[1][i][j] = ((dp[1][i][j] % mod) + mod) % mod;
        }
        for(int j = 1; j <= i; j++) {
            sum[1][i][j] = sum[1][i][j-1] + dp[1][i][j];
            sum[1][i][j] %= mod;
        }
    }

    ll sumcnt = 0;
    ll num = 1;
    for(auto i : cnt) {
        num = (((num * sum[i.fi][i.se][i.se]) % mod) * C[sumcnt+i.se][i.se]) % mod;
        sumcnt += i.se;
    }
    cout << ans << ' ' << num << endl;
}