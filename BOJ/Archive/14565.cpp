#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(!b) return a;
    return gcd(b, a % b);
}

ll exEuclid(ll a, ll b, ll &s, ll &t) { 
    if(b == 0) { 
        s = 1; t = 0; 
        return a; 
    } 
    ll gcd = exEuclid(b, a%b, s, t); 
    ll temp = t; 
    t = s - (a / b)*t; 
    s = temp; 
    if(s <= 0) {    
        s += b; 
        t -= a;
    } 
    return gcd; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, a;
    cin >> n >> a;
    ll c, k;
    ll g = exEuclid(a, n, c, k);
    if(g == 1) cout << n - a << '\n' << c;
    else cout << n - a << '\n' << -1;
}