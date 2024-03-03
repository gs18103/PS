#include "railroad.h"
#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define lob lower_bound
#define upb upper_bound
#define all(v) v.begin(), v.end()
 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
const int MAX = 505050;
const int INF = 1e9;
const ll LINF = 1e18;
 
int p[2*MAX], deg[2*MAX];
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
void uni(int x, int y) {p[find(y)] = find(x);}
struct Edge {int u, v, w; Edge(int u, int v, int w) : u(u), v(v), w(w) {}};
 
ll plan_roller_coaster(vector<int> s, vector<int> t) {
    int n = (int) s.size();
    vector <int> X;
    for(int i = 0; i < n; i++) X.eb(s[i]), X.eb(t[i]);
    sort(all(X)); X.erase(unique(all(X)), X.end());
    for(int i = 1; i <= X.size(); i++) p[i] = i;
    for(int i = 0; i < n; i++) {
        s[i] = lob(all(X), s[i]) - X.begin();
        t[i] = lob(all(X), t[i]) - X.begin();
        deg[s[i]]++;
        deg[t[i]]--;
        uni(s[i], t[i]);
    }
    int cur = 1;
    ll ans = 0;
    vector <Edge> E;
    for(int i = X.size()-1; i >= 0; i--) {
        cur += deg[i];
        if(cur < 0){
            ans -= (ll)cur * (X[i] - X[i-1]);
            uni(i-1, i);
        } 
        if(cur > 0) uni(i, i-1);
        else if(cur == 0) E.eb(i, i-1, X[i] - X[i-1]);
    }
    sort(all(E), [](Edge a, Edge b){return a.w < b.w;});
    for(auto i : E) {
        if(find(i.u) == find(i.v)) continue;
        ans += i.w;
        uni(i.u, i.v);
    }
    return ans;
}