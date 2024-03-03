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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector <ll> A(m), B(m);
    for(int i = 0; i < m; i++) {
        cin >> A[i];
    }

    ll x = (1LL << m) - 1 + n;
    vector <bool> chk(m);
    for(int i = 0; i < m; i++) {
        if(x >> i & 1) {
            B[i] = A[i] * ((x >> i) - 1);
            x -= (1LL << i);
            chk[i] = true;
        }
    }
    for(int i = m - 1; i >= 0; i--) {
        if(chk[i]) continue;
        B[i] = A[i] * ((x >> i) - 1);
        x -= (1LL << i);
    }
    for(int i = 0; i < m; i++) {
        cout << B[i] << ' ';
    }
}
