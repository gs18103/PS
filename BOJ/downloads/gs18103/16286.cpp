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

const int MAX = 505050;
const int INF = 1e9;
const ll LINF = 1e18;

ll a[MAX], sum[MAX];
bool dp[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    ll w;
    cin >> w >> n;  
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    ll lb = 1, ub = w;
    while(lb < ub) {
        ll m = lb + ub + 1 >> 1;
        int p = 0;
        for(int i = 1; i <= n; i++) dp[i] = false;
        dp[0] = true;
        int cnt = 0, p1 = 0, p2 = 0;
        for(int i = 1; i <= n; i++) {
            while(p2 < i && sum[i] - sum[p2] >= m) {
                if(dp[p2]) cnt++;
                p2++;
            }
            while(p1 < i && sum[i] - sum[p1] > w) {
                if(dp[p1]) cnt--;
                p1++;
            }
            if(cnt > 0) dp[i] = true;
        }
        if(dp[n]) lb = m;
        else ub = m - 1;
    }
    cout << (w - lb) * (w - lb);
}