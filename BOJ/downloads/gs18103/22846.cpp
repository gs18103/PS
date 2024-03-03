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

vector <int> d[MAX];
int k;
bool dp[MAX], chk[MAX];

bool f(int x) {
    if(x > k) return false;
    if(chk[x]) return dp[x];
    chk[x] = true;
    dp[x] = false;
    for(auto i : d[x]) {
        dp[x] = dp[x] || f(x + i);
    }
    dp[x] = !dp[x];
    return dp[x];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> k;
    for(int i = 1; i <= k; i++) {
        for(int j = i; j <= k; j += i) {
            d[j].eb(i);
        }
    }
    if(!f(1)) cout << "Kali";
    else cout << "Ringo";
}