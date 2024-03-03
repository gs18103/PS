#include <bits/stdc++.h>
using namespace std;
#define REP0(i,n) for(int i=0; i<n; i++)
#define REP1(i,n) for(int i=1; i<=n; i++)
#define vint vector<int>
#define pb push_back
typedef long long ll;


void solve()
{
    int n,m; cin>>n>>m;
    vector<pair<ll, ll> > v(n);

    REP0(i,m)
    {
        ll a,b,scorea, scoreb;
        cin>>a>>b>>scorea>>scoreb;
        v[a-1].first+=scorea;
        v[a-1].second += scoreb;
        v[b-1].first += scoreb;
        v[b-1].second += scorea;
    }
    vector<double> expec;

    REP0(i,n)
    {
        if(v[i].first==0&&v[i].second==0)
        {
            expec.pb(0);
        }
        else{
            expec.pb((double)v[i].first*v[i].first/((double)v[i].first*v[i].first+v[i].second*v[i].second));
            
        }
    }
    //for(auto x : expec)cout<<x<<endl;
    sort(expec.begin(), expec.end());

    cout<<(ll)(expec[(int)expec.size() - 1]*1000)<<endl;
    cout<<(ll)(expec[0]*1000)<<endl;





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