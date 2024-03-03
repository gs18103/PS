#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+9;

long long dp[1010101];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int q;
    cin >> q;
    
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= 1000000; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % mod;
    }
    
    while(q--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}