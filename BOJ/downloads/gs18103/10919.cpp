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
 
const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
 
long long delivery(int N, int K, int L, int p[]) {
    vector <ll> l, r, suml, sumr;
    for(int i = 0; i < N; i++) {
        if(p[i] == 0) l.eb(p[i]), r.eb(p[i]);
        else if(p[i] <= L / 2) l.eb(p[i]);
        else r.eb((ll)L-p[i]);
    }
    suml.eb(0), sumr.eb(0);
    for(int i = 1; i <= l.size(); i++) {
        if(i < K) suml.eb(l[i-1]);
        else suml.eb(suml[i-K] + l[i-1]);
    }
    sort(all(r));
    for(int i = 1; i <= r.size(); i++) {
        if(i < K) sumr.eb(r[i-1]);
        else sumr.eb(sumr[i-K] + r[i-1]);
    }
    ll ans = (suml.back() + sumr.back()) * 2;
    for(int i = max(1, K - (int)r.size()); i <= min(K-1, (int)l.size()); i++) {
        ans = min(ans, (suml[suml.size()-1-i] + sumr[sumr.size()-1-K+i]) * 2 + L);
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n, k, l;
    cin >> n >> k >> l;
    int p[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cout << delivery(n, k, l, p);
}