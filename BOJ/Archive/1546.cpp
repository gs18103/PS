#include <bits/stdc++.h>

using namespace std;

int cnt[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    double sum = 0, mx = 0;
    for(int i = 1; i <= n; i++) {
        double t;
        cin >> t;
        mx = max(mx, t);
        sum += t;
    }
    cout << sum * 100 / mx / n << endl;
}