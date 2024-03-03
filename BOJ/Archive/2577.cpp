#include <bits/stdc++.h>

using namespace std;

int cnt[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c;
    cin >> a >> b >> c;
    a = a * b * c;
    while(a > 0) {
        cnt[a%10]++;
        a /= 10;
    }
    for(int i = 0; i < 10; i++) {
        cout << cnt[i] << '\n';
    }
}