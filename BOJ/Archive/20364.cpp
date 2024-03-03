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

bool chk[1<<20];

int dfs(int x, int b, int t) {
    if(chk[x]) return x;
    if(x == t) return chk[x] = true, 0;
    if(t >> b & 1) return dfs(x<<1|1, b-1, t);
    else return dfs(x<<1, b-1, t);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    while(q--) {
        int x;
        cin >> x;
        int bit = 0;
        for(int i = 0; i < 20; i++) {
            if(x >> i & 1) bit = i;
        }
        cout << dfs(1, bit - 1, x) << '\n';
    }
}