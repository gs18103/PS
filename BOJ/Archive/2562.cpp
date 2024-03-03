#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int mx = 0, idx = 0;
    for(int i = 1; i <= 9; i++) {
        int x;
        cin >> x;
        if(x > mx) {
            mx = x;
            idx = i;
        }
    }
    cout << mx << endl;
    cout << idx << endl;
}