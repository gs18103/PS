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

const int MAX = 303;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 100030001;

bool chk[MAX][MAX];
ll dp[MAX][MAX];

ll f(int n, int l) {
    if(n == 0) {  
        if(l >= 0) return 1LL;  
        else return 0LL;  
    } 
    if(chk[n][l]) return dp[n][l];
    chk[n][l] = true;
    for(int i = 0; i < n; i++) {
        dp[n][l] += f(i, l - 1) * f(n - 1 - i, l - 1);
        dp[n][l] %= mod;
    }
    return dp[n][l];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, l;
    cin >> n >> l;
    cout << (f(n, l) - f(n, l - 1) + mod) % mod;
}