#include <bits/stdc++.h>

using namespace std;

bool chk[44];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 1; i <= 10; i++) {
        int x;
        cin >> x;
        chk[x%42] = true;
    }
    int ans = 0;
    for(int i = 0; i < 42; i++) {
        if(chk[i]) ans++;
    }
    cout << ans << endl;
}