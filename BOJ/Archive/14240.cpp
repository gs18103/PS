#include <bits/stdc++.h>
#define em emplace
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 505050;
const int INF = 1 << 30;
const ll LINF = 1LL << 62;

ll arr[MAX], sum[MAX], dp[MAX];

pll line[4*MAX];

ll f(pll a, ll x) {
    return a.fi * x + a.se;
}

void add_line(int node, int s, int e, pll val) {
    int m = (s + e) >> 1;
    bool left = f(val, s) > f(line[node], s);
    bool mid = f(val, m) > f(line[node], m);
    if(mid) swap(line[node], val);
    if(e - s == 1) return;
    if(left != mid) add_line(node<<1, s, m, val);
    else add_line(node<<1|1, m, e, val);
}

ll cal(int node, int s, int e, int x) {
    int m = (s + e) / 2;
    if(e - s == 1) return f(line[node], x);
    if(x < m) return max(f(line[node], x), cal(node<<1, s, m, x));
    else return max(f(line[node], x), cal(node<<1|1, m, e, x));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    reverse(arr+1, arr+n+1);
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + arr[i];
    }
    ll cur = 0;
    add_line(1, 0, n, make_pair(0, 0));
    for(int i = 1; i <= n; i++) {
        dp[i] = cal(1, 0, n, i);
        cur += (i - 1) * arr[i];
        add_line(1, 0, n, make_pair(-sum[i], cur));
    }

    ll ans = 0, ssum = 0;
    for(int i = 1; i <= n; i++) {
        ssum += sum[i];
        ans = max(ans, ssum + dp[i]);
    }
    cout << ans;
}