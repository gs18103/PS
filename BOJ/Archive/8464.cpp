#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int d[202020];
bool chk[202020];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    ll n;
    cin >> n;
    ll lb = 1, ub = 4 * n;
    for(ll i = 2; i <= 200000; i++) {
        if(chk[i]) continue;
        d[i] = 1;
        for(ll j = i * i; j <= 200000; j += i) {
            chk[j] = true;
        }
        for(int j = 2; j <= 200000 / i; j++) {
            if(j % i == 0) continue;
            d[i*j] = -d[j];
        }
    }
    while(lb < ub) {
        ll m = (lb + ub) >> 1;
        ll cnt = 0;
        for(ll i = 2; i * i <= m; i++) {
            cnt += d[i] * (m / (i * i));
        }
        if(cnt < n) lb = m + 1;
        else ub = m;
    }
    cout << lb << endl;
}