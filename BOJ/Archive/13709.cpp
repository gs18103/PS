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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

ll A[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        sort(A+i, A+n, [](ll a, ll b) {
            return a > b;
        });
        if(A[i] == 0) break;
        int bit = 1;
        while(A[i] >> bit) bit++;
        bit--;
        if(~ans >> bit & 1) ans ^= A[i];
        for(int j = i + 1; j < n; j++) {
            if(A[j] >> bit & 1) A[j] ^= A[i];
        }
    }
    cout << ans;
}