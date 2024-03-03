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

    int n;
    cin >> n;
    vector <int> A(n+2);
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int l = n, r = 1;
    for(int i = 1; i < n; i++) {
        if(A[i] > A[i+1]) {
            l = i;
            break;
        }
    }
    for(int i = n; i > 1; i--) {
        if(A[i] < A[i-1]) {
            r = i;
            break;
        }
    }

    int ans = 0;
    for(int i = 2; i < n; i++) {
        if(l >= i - 1 && r <= i + 1 && A[i-1] <= A[i+1]) ans++;
    }
    if(r <= 2) ans++;
    if(l >= n - 1) ans++;
    cout << ans;
}