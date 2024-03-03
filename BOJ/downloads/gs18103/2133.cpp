#include <bits/stdc++.h>

using namespace std;

int dp[3][33];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        if(i%2==1) dp[1][i]=0;
        if(i%2==0) dp[2][i]=0;
    }
    dp[2][1]=1;
    dp[1][2]=3;
    for(int i=3; i<=n; i++) {
        dp[1][i]=dp[1][i-2]+2*dp[2][i-1];
        dp[2][i]=dp[1][i-1]+dp[2][i-2];
    }
    printf("%d", dp[1][n]);
}
