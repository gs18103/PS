#include <bits/stdc++.h>

using namespace std;

long long f(int n) {
    if(n == 0) return 1;
    return f(n - 1) * n;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    cout << f(n);
}