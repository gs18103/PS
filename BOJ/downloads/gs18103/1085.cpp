#include <bits/stdc++.h>

using namespace std;

int p[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min({x, y, w - x, h - y}) << endl;
}