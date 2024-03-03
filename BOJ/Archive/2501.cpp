#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector <int> d;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) d.emplace_back(i);
    }
    if(d.size() < k) cout << 0;
    else cout << d[k-1] << endl;
}