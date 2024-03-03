#include <bits/stdc++.h>
using namespace std;

int cnt[2020202], a[101010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, x;
    long long ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    for(int i = 1; i <= n; i++) {
        if(x > a[i]) ans += cnt[x-a[i]];
        cnt[a[i]]++;
    }
    cout << ans;
}