#include <bits/stdc++.h>
using namespace std;
#define REP0(i,n) for(int i=0; i<n; i++)
#define REP1(i,n) for(int i=1; i<=n; i++)
#define vint vector<int>
#define pb push_back
typedef long long ll;



void solve()
{
    int n; cin>>n;
    bool pos = false;

    for(int b=2; b<=64; b++)
    {
        int num = n;
        bool ispalindrome =true;

        vint temp;
        while(num>=1)
        {
            temp.pb(num%b);
            num = num/b;
        }
        int sz  =  (int)temp.size();
        for(int i=0; i<sz/2; i++)
        {
            if(temp[i] !=temp[sz-i-1])
            {
                ispalindrome =false;

            }
        }

        if(ispalindrome)
        {
            pos=true;
            break;
        }
        






    }


    if(pos)cout<<1<<endl;
    else cout<<0<<endl;

    
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