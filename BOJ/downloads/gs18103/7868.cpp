#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 1010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll p1, p2, p3, i, x, y, z;
    cin >> p1 >> p2 >> p3 >> i; 
    vector <ll> v;
    for(x = 1; x <= LINF / p1; x *= p1) {
        for(y = 1; y <= LINF / p2; y *= p2) {
            for(z = 1; z <= LINF / p3; z *= p3) {
                if(x == 1 && y == 1 && z == 1) continue;
                if(x <= LINF / y && x * y <= LINF / z) v.eb(x * y * z);
            }
        }
        for(z = 1; z <= LINF / p3; z *= p3) {
            if(x == 1 && y == 1 && z == 1) continue;
            if(x <= LINF / y && x * y <= LINF / z) v.eb(x * y * z);
        }
    }
    for(y = 1; y <= LINF / p2; y *= p2) {
        for(z = 1; z <= LINF / p3; z *= p3) {
            if(x == 1 && y == 1 && z == 1) continue;
            if(x <= LINF / y && x * y <= LINF / z) v.eb(x * y * z);
        }
    }
    sort(all(v));
    cout << v[i-1];
}