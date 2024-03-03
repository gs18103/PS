#include <bits/stdc++.h>

using namespace std;

int dp[101010];
int sq[404];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    int sz = 0;
    for(int i = 1; i * i <= n; i++) {
        sq[++sz] = i * i;
    }

    for(int i = 1; i <= n; i++) {
        dp[i] = i;
    }

    for(int i = 2; i <= sz; i++) {
        for(int j = sq[i]; j <= n; j++) {
            dp[j] = min(dp[j], dp[j-sq[i]] + 1);
        }
    }
    cout << dp[n] << endl;
}