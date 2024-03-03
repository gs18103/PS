#include <bits/stdc++.h>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define eb emplace_back
#define em emplace

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int INF = 1 << 30;
const ll LINF = 1LL << 62;
const int MAX = 303030;

ll ans = 0;
struct node{
    priority_queue <ll> L;
    priority_queue <ll, vector <ll>, greater <ll> > R;
    int sz = 0;
    void merge(node &X) {
        if(X.sz == 0) return;
        sz += X.sz;
        while(!X.L.empty()) {
            ll temp = X.L.top();
            X.L.pop();
            if(temp > R.top()){
                ans += temp - R.top();
                L.em(R.top()); R.pop();
                R.em(temp);
            }
            else L.em(temp);
        }
        while(!X.R.empty()) {
            ll temp = X.R.top();
            X.R.pop();
            if(temp < L.top()){
                ans += L.top() - temp;
                R.em(L.top()); L.pop();
                L.em(temp);
            }
            else R.em(temp);
        }
    }
    void modify(ll val) {
        ll Rt = 0, Lt = 0;
        if(!R.empty()) {Rt = R.top();}
        if(!L.empty()) {Lt = L.top(); L.pop();}
        while(!R.empty()) R.pop(), sz--;
        R.push(Rt + val);
        L.push(Lt + val);
        sz += 2;
    }
} dp[MAX];

int p[MAX], idx[MAX];
ll c[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 2; i <= n + m; i++) {
        cin >> p[i] >> c[i];
        idx[i] = i;
    }
    for(int i = n + m; i > 1; i--) {
        dp[idx[i]].modify(c[i]);
        if(dp[idx[p[i]]].sz < dp[idx[i]].sz) {
            dp[idx[i]].merge(dp[idx[p[i]]]);
            idx[p[i]] = idx[i];
        }
        else dp[idx[p[i]]].merge(dp[idx[i]]);
    }
    cout << ans;
}