#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 505050;
const int INF = 1e9;
const ll LINF = 9e18;

bool chk[MAX];
int ans[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, c = 1;
    cin >> n;
    ans[1] = 1;
    for(ll i = 2; i <= n; i++) {
        if(chk[i]) continue;
        c++;
        ans[i] = c;
        for(ll j = i * i; j <= n; j += i) {
            chk[j] = true;
            ans[j] = c;
        }
    }

    cout << c << '\n';
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}