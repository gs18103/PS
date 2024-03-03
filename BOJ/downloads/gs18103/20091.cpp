#include "mountains.h"
#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

ll ccw(pll a, pll b, pll c) {
    return (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
}

int maximum_deevs(vector<int> y) {
    
    int n = y.size();
	vector <vector <int> > dp(n);
    for(int i = 0; i < n; i++) dp[i].resize(i+1);

    dp[0][0] = 1;
    for(int i = 1; i < n; i++) {
        dp[i][i] = 1;
        for(int j = i - 1; j >= 0; j--) {
            dp[i][j] = dp[i-1][j];
        }
        int idx = i - 1;
        for(int j = i - 2; j >= 0; j--) {
            if(ccw({j, y[j]}, {idx, y[idx]}, {i, y[i]}) >= 0) {
                idx = j;
                dp[i][j] = max(dp[i][j], dp[i][j+1]);
            }
            else {
                dp[i][j] = max(dp[i][j], dp[i][idx+1] + dp[idx-1][j]);
            }
        }
    }
    return dp[n-1][0];
}