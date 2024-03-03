#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 303030;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <pii> G(n);
    vector <int> C(k);
    
    for(int i = 0; i < n; i++) {
        cin >> G[i].fi >> G[i].se;
    }
    for(int i = 0; i < k; i++) {
        cin >> C[i];
    }
    
    sort(all(G));
    sort(all(C));
    
    int idx = 0;
    ll ans = 0;
    priority_queue <int> pq;
    for(int i = 0; i < k; i++) {
        while(idx < n && G[idx].fi <= C[i]) {
            pq.em(G[idx].se);
            idx++;
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}
