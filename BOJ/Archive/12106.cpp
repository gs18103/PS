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

const int MAX = 101;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+9;

vector <int> get_fail(string t) {
    int p = 0, n = t.size();
    vector <int> F(n);
    for(int i = 1; i < n; i++) {
        while(p && t[p] != t[i]) p = F[p-1];
        if(t[p] == t[i]) p++;
        F[i] = p;
    }
    return F;
}

ll dp[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int m = s.size();
    
    vector <int> F = get_fail(s);

    dp[0][F[m-1]] = 1;

    for(int i = 0; i <= n - m; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] %= mod;
            if(i == n - m) continue;
            int p = j, cnt = 26;
            vector <bool> chk(26);
            while(p) {
                if(!chk[s[p]-'a']) dp[i+1][p+1] += dp[i][j], cnt--, chk[s[p]-'a'] = true;
                p = F[p-1];
            }
            if(!chk[s[0]-'a']) dp[i+1][1] += dp[i][j], cnt--;
            dp[i+1][0] += dp[i][j] * cnt;
        }
    }
    
    ll ans = 0, e = 1;
    for(int i = n - m; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            ans += e * dp[i][j];
            ans %= mod;
        }
        e = (e * 26) % mod;
    }
    cout << ans;
}