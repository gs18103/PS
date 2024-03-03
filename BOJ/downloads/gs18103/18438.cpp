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

const int MAX = 7070;
const int INF = 1e9;
const ll LINF = 1e18;

string s, t, ans;

int dp1[2][MAX], dp2[2][MAX];

void LCS(int l1, int r1, int l2, int r2) {
    if(l1 == r1) {
        for(int i = l2; i <= r2; i++) {
            if(s[l1] == t[i]) {
                ans += t[i];
                break;
            }
        }
        return;
    }

    int m = l1 + r1 >> 1;
    for(int i = l2 - 1; i <= r2 + 1; i++) dp1[0][i] = dp1[1][i] = dp2[0][i] = dp2[1][i] = 0;
    for(int i = l1; i <= m; i++) {
        for(int j = l2; j <= r2; j++) {
            if(s[i] == t[j]) dp1[i&1][j] = dp1[!(i&1)][j-1] + 1;
            else dp1[i&1][j] = max(dp1[!(i&1)][j], dp1[i&1][j-1]);
        }
    }
    for(int i = r1; i > m; i--) {
        for(int j = r2; j >= l2; j--) {
            if(s[i] == t[j]) dp2[i&1][j] = dp2[!(i&1)][j+1] + 1;
            else dp2[i&1][j] = max(dp2[!(i&1)][j], dp2[i&1][j+1]);
        }
    }

    int mx = -1, idx;
    for(int i = l2 - 1; i <= r2; i++) {
        if(mx < dp1[m&1][i] + dp2[!(m&1)][i+1]) {
            mx = dp1[m&1][i] + dp2[!(m&1)][i+1];
            idx = i;
        }
    }
    LCS(l1, m, l2, idx);
    LCS(m+1, r1, idx+1, r2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> s >> t;
    s = " " + s, t = " " + t;
    LCS(1, s.size()-1, 1, t.size()-1);
    cout << ans.size() << '\n';
    cout << ans;
}