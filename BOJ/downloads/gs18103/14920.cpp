#include <iostream>

using namespace std;

int C(int n) {
    if(n == 1) return 1;
    if(n % 2 == 0) return C(n / 2) + 1;
    else return C(3 * n + 1) + 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    cout << C(n);

    return 0;
}