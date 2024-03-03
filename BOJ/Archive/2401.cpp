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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 10101;
const int INF = 1e9;
const ll LINF = 1e18;

int F[505][MAX];

void get_fail(int x, string &t) {
    int p = 0, n = t.size();
    for(int i = 0; i < n; i++) {
        F[x][i] = 0;
    }
	for(int i = 1; i < n; i++) {
		while(p > 0 && t[i] != t[p]) p = F[x][p-1];
		if(t[i] == t[p]) p++;
		F[x][i] = p;
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s;
    cin >> s;
    int n;
    cin >> n;
    vector <string> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        get_fail(i, t[i]);
    }
    vector <int> dp(s.size()+1);

    vector <int> p(n);
    int L = s.size();
    for(int i = 0; i < L; i++) {
        dp[i+1] = max(dp[i+1], dp[i]);
        for(int j = 0; j < n; j++) {
            while(p[j] && t[j][p[j]] != s[i]) p[j] = F[j][p[j]-1];
            if(s[i] == t[j][p[j]]) p[j]++;
            if(p[j] == t[j].size()) {
                dp[i+1] = max(dp[i+1], dp[i+1-p[j]] + p[j]);
                p[j] = F[j][p[j]-1];
            }
        }
    }
    cout << dp[L];
}