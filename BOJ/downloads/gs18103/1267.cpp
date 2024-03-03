#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int M = 0, Y = 0, n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        Y += 10 * (val / 30 + 1);
        M += 15 * (val / 60 + 1);
    }
    if(Y < M) cout << "Y " << Y;
    else if(Y == M) cout << "Y M " << Y;
    else cout << "M " << M;
}