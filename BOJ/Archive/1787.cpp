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
vector <int> get_fail(string t) {
    int p = 0, n = t.size();
    vector <int> F(n);
    for(int i = 1; i < n; i++) {
        while(p && t[p] != t[i]) p = F[p-1];
        if(t[p] == t[i]) p++;
        F[i] = p;
    }
    return F;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    vector <int> F = get_fail(s);
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        if(F[i] == 0) continue;
        if(F[F[i]-1]) F[i] = F[F[i]-1];
        //cout << i << ' ' << F[i] << endl;
        ans += (i + 1 - F[i]);
    }
    cout << ans;
}