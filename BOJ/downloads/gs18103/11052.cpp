#include <bits/stdc++.h>

using namespace std;

int p[1010], dp[1010];
bool chk[1010];

int f(int n) {
    if(n == 0) return 0;
    if(chk[n]) return dp[n];
    chk[n] = true;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, f(n - i) + p[i]);
    }
    dp[n] = ans;
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    printf("%d", f(n));
}
