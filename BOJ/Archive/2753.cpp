#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    if(n % 400 == 0) cout << 1 << endl;
    else if(n % 100 == 0) cout << 0 << endl;
    else if(n % 4 == 0) cout << 1 << endl;
    else cout << 0 << endl;
}