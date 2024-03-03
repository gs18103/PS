#include <bits/stdc++.h>

using namespace std;

bool chk[101010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b, k;
    cin >> a >> b >> k;
    if(a == 0) return !(cout << 0);
    if(a == k) return !(cout << 1);
    if(a + b <= k) return !(cout << -1);
    
    int x = 2 * (a + b - k);
    int odd = 2 * max((k - a + x - 1) / x, (a + k - 1) / (2 * k)) + 1;
    int even = 2 * max((a + x - 1) / x, (a - 1) / (2 * k) + 1);
    if(k & 1) {
        if(a & 1) cout << odd;
        else cout << even;
    }
    else {
        if(a & 1) cout << -1;
        else cout << min(even, odd);
    }

    return 0;
}