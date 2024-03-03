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

int A[MAX], cnt[1<<17];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int c;  
        cin >> c;
        for(int j = 0; j < c; j++) {
            int p; cin >> p;
            A[i] |= (1 << (p - 1));
        }
        cnt[A[i]]++;
    }

    for(int i = 17; i > 0; i--) {
        for(int j = 0; j < (1 << 17); j++) {
            if(j >> i & 1) {
                for(int k = i - 1; k >= 0; k--) {
                    if(j >> k & 1) break;
                    cnt[j] += cnt[j ^ (1 << i) ^ (1 << k)];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << cnt[A[i]] << ' ';
    }
}