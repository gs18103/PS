#include <bits/stdc++.h>
using namespace std;
#define REP0(i,n) for(int i=0; i<n; i++)
#define REP1(i,n) for(int i=1; i<=n; i++)
typedef long long ll;



void solve()
{
    int k; cin>>k;
    ll ar[k+1];
    REP1(i,k)cin>>ar[i];
    ll sum[k+1];
    sum[0]=0;
    REP1(i,k)sum[i] = sum[i-1]  +ar[i];

    ll dp[k+1][k+1];

    REP1(i,k)dp[i][i] = 0;
    for(int len=2 ; len<=k; len++)
    {
        for(int left=1; left<=k-len+1; left++)
        {
            int right = left+len-1;

            dp[left][right]=LLONG_MAX;
            for(int m=left; m<right; m++)
            {
                dp[left][right] = min(dp[left][right] , dp[left][m] + dp[m+1][right] + sum[right]-sum[left-1]);

            }

        }
    }

    cout<<dp[1][k]<<endl;
}

int main()
{
    
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}