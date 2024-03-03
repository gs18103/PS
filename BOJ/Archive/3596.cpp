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

const int MAX = 2020;
const int INF = 1e9;
const ll LINF = 1e18;

int dp[MAX]; 
bool chk[MAX];

int f(int n) {
    if(n == 0) return 0;
    if(n <= 3) return 1;
    if(chk[n]) return dp[n];
    chk[n] = true;
    vector <bool> tchk(n+10);
    for(int i = 1; i <= (n + 1) / 2; i++) {
        if(i <= 3) tchk[f(n-i-2)] = true;
        else tchk[f(n-i-2)^f(i-3)] = true;                              
    }
    for(int i = 0; i <= n + 9; i++) {
        if(!tchk[i]) return dp[n] = i;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    cout << (f(n) == 0 ? 2 : 1);
}