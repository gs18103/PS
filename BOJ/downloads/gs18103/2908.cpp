#include <bits/stdc++.h>

using namespace std;

int cnt[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    cin >> a >> b;
    a = a / 100 + ((a / 10) % 10) * 10 + (a % 10) * 100;
    b = b / 100 + ((b / 10) % 10) * 10 + (b % 10) * 100;
    cout << max(a, b) << endl;
}