#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        while(n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
}