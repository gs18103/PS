#include <bits/stdc++.h>

using namespace std;

int a[2020], d[2020];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u, v; cin >> u >> v;
        a[u] = v;
    }
    
    int ans = 0;
    for(int i = 1; i <= 500; i++) {
        if(a[i] == 0) continue;
        d[i] = 1;
        for(int j = 1; j < i; j++) {
            if(a[j] < a[i]) d[i] = max(d[i], d[j] + 1);
        }
        ans = max(ans, d[i]);
    }
    cout << n - ans;
}