#include <bits/stdc++.h>
#define __float128 __float128
using namespace std;

constexpr __float128 PI = 3.1415926535897932384626433832795028841971693993751058209749445923Q;

__float128 mysin(__float128 x) {
    __float128 ret = 0.0;
    __float128 xp = x, sgn = 1;
    for(int i = 1; xp >= 1e-40; i += 2) {
        ret += sgn * xp;
        xp *= x * x / ((__float128)(i + 1) * (i + 2));
        sgn = -sgn;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cout << fixed; cout.precision(6);
	int A, B, C;
	cin >> A >> B >> C;
	__float128 lo = (__float128)(C - B) / A, hi = (__float128)(B + C) / A;
    
	while(hi-lo >= 1e-25){
		__float128 x = (lo+hi)/2;
        __float128 modx = x - floor((double)(x / (2 * PI))) * 2 * PI;
		(A*x + B*mysin(modx) < C ? lo : hi) = x;
	}
    hi = hi * 10000000;
    long long ans = (long long)hi;
    if(ans % 10 >= 5) ans += 10;
    ans /= 10;
    cout << (double)ans / 1000000 << '\n';
}