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

const int MAX = 202;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

int dp[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> a, b;
    for(int i = 0; i < n; i++) {
        int u;
        cin >> u;
        if(u > 0) a.eb(u);
        else b.eb(-u);
    }
    sort(all(a));
    sort(all(b));
    if(a.empty()) {
        cout << -b[1] << ' ' << -b[0];
        return 0;
    }
    if(b.empty()) {
        cout << a[0] << ' ' << a[1];
        return 0;
    }
    int idx1 = 0, idx2 = 0, ans = INF, ansa, ansb;
    while(idx1 < a.size() && idx2 < b.size()) {
        ans = min(ans, abs(a[idx1] - b[idx2]));
        if(ans == abs(a[idx1] - b[idx2])) {
            ansa = a[idx1];
            ansb = b[idx2];
        }
        if(a[idx1] < b[idx2]) idx1++;
        else idx2++;
    }
    if(a.size() >= 2 && ans > a[0] + a[1]) {
        ansa = a[1], ansb = -a[0];
    }
    if(b.size() >= 2 && ans > b[0] + b[1]) {
        ansb = b[1], ansa = -b[0];
        ans = b[0] + b[1];
    }
    cout << -ansb << ' ' << ansa;
}