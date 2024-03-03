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
const ll mod = 998244353;

bool g[26][26];
int cntl[26][26], s[2020202];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    string S;
    cin >> S;
    for(int i = 0; i < n; i++) {
        s[i] = S[i] - 'a';
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        string t;
        cin >> t;
        g[t[0]-'a'][t[1]-'a'] = true;
    }

    int lidx = 0, ridx = 0;
    int totl = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        lidx = max(lidx, i);
        while(lidx + 1 < n && g[s[lidx]][s[lidx+1]] && totl < m) {
            if(cntl[ s[lidx] ][ s[lidx+1] ] == 0) totl++;
            cntl[ s[lidx] ][ s[lidx+1] ]++;
            lidx++;
        }
        ridx = max(ridx, lidx);
        while(ridx + 1 < n && g[s[ridx]][s[ridx+1]]) {
            ridx++;
        }
        if(totl == m) ans += ridx - lidx + 1;
        if(lidx > i) {
            cntl[ s[i] ][ s[i+1] ]--;
            if(cntl[ s[i] ][ s[i+1] ] == 0) totl--;
        }
    }
    cout << ans << endl;
}