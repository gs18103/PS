#include "molecules.h"
#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
const int MAX = 505050;
const int INF = INT_MAX >> 1;
const ll LINF = LLONG_MAX >> 1;
const ll mod = 1e9+9;
 
vector<int> find_subset(int l, int u, vector<int> w) {
    vector <int> ans;
    vector <pll> W;
    for(int i = 0; i < w.size(); i++) W.eb(w[i], i);
    sort(all(W));
    ll sumh = 0, suml = 0, U = u, L = l;
    for(int i = 1; i <= W.size(); i++) {
        sumh += W[W.size()-i].fi, suml += W[i-1].fi;
        if(sumh >= L && suml <= U) {
            if(suml >= L) {
                for(int j = 0; j < i; j++) {
                    ans.eb(W[j].se);
                }
                break;
            }
            for(int j = 0; j + i < W.size(); j++) {
                ll tsum = suml - W[j].fi + W[j+i].fi;
                if(tsum >= L && tsum <= U) {
                    for(int k = 0; k < i; k++) {
                        ans.eb(W[j+k+1].se);
                    }
                    break;
                }
                suml = tsum;
            }
            break;
        }
    }
    return ans;
}