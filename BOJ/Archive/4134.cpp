#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll n;
    int q;
    cin >> q;
    while(q--) {
        cin >> n;
        if(n < 2) n = 2;
        bool flag = false;
        while(1) {
            for(ll i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    flag = true;
                    break;
                }
            }
            if(!flag) break;
            n++; flag = false;
        }
        cout << n << '\n';
    }
}