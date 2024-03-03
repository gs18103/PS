#include <bits/stdc++.h>

using namespace std;

int digisum(int k) {
    int sum = k;
    while(k > 0) {
        sum += k % 10;
        k /= 10;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(digisum(i) == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}