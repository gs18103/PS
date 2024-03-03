#include<bits/stdc++.h>
using namespace std;

int in[1010], sum[1010], dp[1010][1010];
int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>in[i];
            sum[i]=sum[i-1]+in[i];
        }
        for(int i=1;i<=n;i++) dp[i][i]=in[i];

        for(int k=2;k<=n;k++){
            for(int i=1;i<=n-k+1;i++){
                int j = i+k-1;

                dp[i][j] = max(in[i]+sum[j]-sum[i]-dp[i+1][j], in[j] + sum[j-1]-sum[i-1]-dp[i][j-1]);
            }
        }
        cout<<dp[1][n]<<"\n";
    }
}