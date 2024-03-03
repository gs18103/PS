#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector <pii> s1, s2;
    int pre;
    cin >> pre;
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        if(i & 1) s1.eb(min(pre, u), max(pre, u));
        else s2.eb(min(pre, u), max(pre, u));
        pre = u;
    }
    sort(all(s1)), sort(all(s2));

    priority_queue <int, vector <int>, greater <int> > pq;
    for(auto i : s1) {
        while(!pq.empty() && pq.top() < i.fi) pq.pop();
        if(!pq.empty() && pq.top() < i.se) {
            cout << "NO\n";
            return;
        }
        pq.push(i.se);
    }
    while(!pq.empty()) pq.pop();
    for(auto i : s2) {
        while(!pq.empty() && pq.top() < i.fi) pq.pop();
        if(!pq.empty() && pq.top() < i.se) {
            cout << "NO\n";
            return;
        }
        pq.push(i.se);
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}