#include <bits/stdc++.h>

using namespace std;

int cnt[10];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    while(n) {
        cnt[n%10]++;
        n /= 10;
    }
    int ans = 0;
    for(int i = 0; i <= 5; i++) {
        if(ans < cnt[i]) ans = cnt[i];
    }
    for(int i = 7; i <= 8; i++) {
        if(ans < cnt[i]) ans = cnt[i];
    }
    if(ans < (cnt[6] + cnt[9] + 1) / 2) ans = (cnt[6] + cnt[9] + 1) / 2;
    cout << ans;
}