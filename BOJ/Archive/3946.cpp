#include <bits/stdc++.h>

using namespace std;

int n;
double l, r;
double dp[2020][2020];
bool chk[2020][2020];

double f(int k, int x) {
    if(k == 0) return (double)x;
    if(chk[k][x]) return dp[k][x];
    chk[k][x] = true;
    return dp[k][x] = f(k-1, x+1) * r + f(k-1, max(0, x-1)) * l + (1.0-l-r) * f(k-1, x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout << fixed; cout.precision(4);

    int q;
    cin >> q;
    while(q--) {
    	cin >> n >> l >> r;
        cout << f(n, 0) << '\n';
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = 0, chk[i][j] = false;
            }
        }
    }
}