#include  <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector <int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll cnt = 1, ans = 0;
    for(int i = 1; i < n; i++) {
        if(A[i-1] < A[i]) cnt++;
        else {
            ans += (cnt * (cnt + 1)) / 2;
            cnt = 1;
        }
    }
    cout << ans + (cnt * (cnt + 1)) / 2 << endl;
}