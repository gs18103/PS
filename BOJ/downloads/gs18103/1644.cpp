#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 4040404;
const int INF = 1e9;
const ll LINF = 1e18;

bool chk[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> p, c;
    for(int i = 2; i <= n; i++) {
        if(!chk[i]) {
            p.eb(i);
        }
        for(int j : p) {
            if(i * j > n) break;
            chk[i*j] = true;
            if(i % j == 0) break;
        }
    }
    
    ll tsum = 0;
    int idx = 0, ans = 0;
    for(int i = 0; i < p.size(); i++) {
        tsum += p[i];
        while(idx <= i && tsum > n) {
            tsum -= p[idx];
            idx++;
        }
        if(tsum == n) ans++;
    }
    cout << ans;
}
