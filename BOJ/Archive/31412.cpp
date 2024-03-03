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
typedef pair <int, ll> pil;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector <ll> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i) a[i] += a[i-1];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int num = 1;
    for(int i = 2; i <= m; i++) num *= i;
    vector <int> perm(m);
    for(int i = 0; i < m; i++) perm[i] = i;

    ll ans = LINF;
    for(int i = 0; i < num; i++) {
        ll lb = 1, ub = 1e12;
        while(lb < ub) {
            ll pre = 0, mid = (lb + ub) / 2;
            for(int j = 0; j < m; j++) {
                int idx = upper_bound(all(a), pre + mid * b[perm[j]]) - a.begin() - 1;
                if(idx < 0) break;
                pre = a[idx];
            }
            if(pre == a[n-1]) ub = mid;
            else lb = mid + 1;
        }
        ans = min(ans, lb);
        next_permutation(all(perm));
    }
    cout << ans << endl;
}