#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> ans(n+1), A(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    if(A[n] < 0) return !(cout << -1);
    int num = 0;
    for(int i = 1; i <= n; i++) {
        if(A[i] < 0) ans[i] = ++num;
    }
    for(int i = n; i >= 1; i--) {
        if(A[i] > 0) ans[i] = ++num;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}