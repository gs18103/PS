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

ll L[MAX], S[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, k;
    ll m;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> L[i];
    }
    cin >> m >> k;

    sort(L+1, L+n+1);
    for(int i = 1; i <= n; i++) {
        S[i] = S[i-1] + L[i];
    }
    ll sum = m * k;
    for(int i = 1; i < n; i++) {
        ll lb = 0, ub = min(m, sum);
        while(lb < ub) {
            ll mid = lb + ub + 1 >> 1;
            int idx = lower_bound(L+i+1, L+n+1, L[i] + mid) - L;
            if((L[i] + mid) * (idx - i - 1) - (S[idx-1] - S[i]) + mid <= sum) lb = mid;
            else ub = mid - 1;
        }
        L[i] += lb;
        sum -= lb;
    }
    L[n] += sum;
    for(int i = 1; i <= n; i++) {
        cout << L[i] << ' ';
    }
}