#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, m;
    cin >> h >> m;
    m -= 45;
    if(m < 0) h--, m += 60;
    if(h < 0) h += 24;
    cout << h << ' ' << m << endl;
}