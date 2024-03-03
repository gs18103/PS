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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> k >> n;
    vector <ll> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }

    ll lb = 1, ub = 3LL*INF;
    while(lb < ub) {
        ll m = lb + ub + 1 >> 1;
        ll cnt = 0;
        for(int i = 0; i < k; i++) {
            cnt += a[i] / m;
        }
        if(cnt >= n) lb = m;
        else ub = m - 1;
    }
    cout << lb;
}