#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 505050;
const int INF = 1e9;
const ll LINF = 1e18;

bool sq(__int128 a, __int128 b) {
    __int128 t = a * b;
    __int128 lb = 1, ub = max(a, b);
    while(lb < ub) {
        __int128 m = lb + ub >> 1;
        if(m * m < t) lb = m + 1;
        else ub = m;
    }
    if(lb * lb == t) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector <ll> v(n), a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        v[i] = a[i];
    }
    sort(all(v));
    for(int i = 0; i < n; i++) {
        if(!sq(a[i], v[i])) return !(cout << "NO");
    }
    cout << "YES";
}