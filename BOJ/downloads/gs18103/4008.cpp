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

const int INF = 1 << 30;
const ll LINF = 1LL << 62;
const int MAX = 101010;

int n;
ll a, b, c, x[10*MAX], sum[10*MAX], dp[10*MAX];

vector <pll> line;

double cross(pll l1, pll l2) {
    return (double)(l1.se - l2.se) / (l2.fi - l1.fi);
}

void push_line(ll a, ll b) {
    while(line.size() >= 2) {
        int sz = line.size();
        if(cross(line[sz-1], line[sz-2]) < cross(line[sz-1], {a, b})) break;
        line.pop_back();
    }
    line.eb(a, b);
}

ll cal(pll l, ll x) {
    return l.fi * x + l.se;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> a >> b >> c;
    push_line(0, 0);
    int idx = 0;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        sum[i] = sum[i-1] + x[i];
        while(idx < line.size() - 1) {
            if(cross(line[idx], line[idx+1]) > sum[i]) break;
            idx++;
        }  
        dp[i] = a * sum[i] * sum[i] + b * sum[i] + c + cal(line[idx], sum[i]);
        push_line(-2 * a * sum[i], dp[i] + a * sum[i] * sum[i] - b * sum[i]);
    }
    cout << dp[n] << endl;
}