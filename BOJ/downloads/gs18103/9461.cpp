#include <bits/stdc++.h>

using namespace std;

long long dp[101];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for(int i = 6; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }   
    
    int q;
    cin >> q;
    while(q--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}