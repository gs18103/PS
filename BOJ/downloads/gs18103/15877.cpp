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

const int MAX = 1010;
const int INF = 1e9;
const ll LINF = 1e18;

int dp[MAX][MAX];
bool chk[5];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            chk[0] = chk[1] = chk[2] = chk[3] = chk[4] = false;
            if(i) chk[dp[i-1][j]] = true;
            if(i && j > 2) chk[dp[i-1][j-3]] = true;
            if(j) chk[dp[i][j-1]] = true;
            if(j && i > 2) chk[dp[i-3][j-1]] = true;
            for(int k = 4; k >= 0; k--) {
                if(!chk[k]) dp[i][j] = k;
            }
        }
    }
    if(!dp[a][b]) cout << "Bob";
    else cout << "Alice";
}