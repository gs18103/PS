#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << (a * a + b * b + c * c + d * d + e * e) % 10 << endl;
}