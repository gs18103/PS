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

    int p, l, v, t = 0;
    cin >> p >> l >> v;
    while(p != 0 && l != 0 && v != 0) {
        t++;
        cout << "Case " << t << ": " << p * (v / l) + min(p, v % l) << '\n';
        cin >> p >> l >> v;
    }
}