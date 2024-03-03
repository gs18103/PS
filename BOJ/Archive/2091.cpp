#include <bits/stdc++.h>

using namespace std;

int dp[5][10101];
int pre[5][10101];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int x, a, b, c, d;
    cin >> x >> a >> b >> c >> d;
    for(int i = 0; i <= x; i++) {
        if(i <= a) dp[1][i] = i;
        else dp[1][i] = -1e9;
    }
    for(int i = 1; i <= x; i++) {
        dp[2][i] = -1e9;
        for(int j = 0; j <= b && i - 5 * j >= 0; j++) {
            dp[2][i] = max(dp[2][i], dp[1][i-5*j] + j);
            if(dp[2][i] == dp[1][i-5*j] + j) pre[2][i] = j;
        }
    }
    for(int i = 1; i <= x; i++) {
        dp[3][i] = -1e9;
        for(int j = 0; j <= c && i - 10 * j >= 0; j++) {
            dp[3][i] = max(dp[3][i], dp[2][i-10*j] + j);
            if(dp[3][i] == dp[2][i-10*j] + j) pre[3][i] = j;
        }
    }
    for(int i = 1; i <= x; i++) {
        dp[4][i] = -1e9;
        for(int j = 0; j <= d && i - 25 * j >= 0; j++) {
            dp[4][i] = max(dp[4][i], dp[3][i-25*j] + j);
            if(dp[4][i] == dp[3][i-25*j] + j) pre[4][i] = j;
        }
    }
    if(dp[4][x] < 0) cout << "0 0 0 0";
    else {
        int A, B, C, D;
        D = pre[4][x];
        C = pre[3][x-25*D];
        B = pre[2][x-25*D-10*C];
        A = x - 25*D - 10*C - 5*B;
        cout << A << ' ' << B << ' ' << C << ' ' << D;
    }
}
