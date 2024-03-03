#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    cout << a << ' ' << b << ' ' << c;
}