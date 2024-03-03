#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << a * b / gcd(a, b) << '\n';
    }
}