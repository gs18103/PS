#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, k = 1;
    cin >> n;
    int i = 1;
    for(i = 1; k < n; i++) {
        k += i * 6;
    }
    cout << i << endl;
}