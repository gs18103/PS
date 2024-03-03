#include <bits/stdc++.h>

using namespace std;

int dp[101][101][101];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;
    a = " " + a, b = " " + b, c = " " + c;

    for(int i = 1; i < a.size(); i++) {
        for(int j = 1; j < b.size(); j++) {
            for(int k = 1; k < c.size(); k++) {
                dp[i][j][k] = max({dp[i][j][k-1], dp[i][j-1][k], dp[i-1][j][k]});
                if(a[i] == b[j] && b[j] == c[k]) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1] + 1);
                }
            }
        }
    }
    cout << dp[a.size()-1][b.size()-1][c.size()-1] << endl;
}