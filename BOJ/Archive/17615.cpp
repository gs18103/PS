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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    
    int mxr = -1, mxb = -1, mnr = n, mnb = n;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') mxr = max(mxr, i), mnr = min(mnr, i);
        if(s[i] == 'B') mxb = max(mxb, i), mnb = min(mnb, i);
    }
    if(mxr < 0 || mxb < 0) return cout << 0, 0;
    int ans = n;
    int cnt = 0;
    for(int i = 0; i <= mxb; i++) {
        if(s[i] == 'R') cnt++;
    }
    ans = min(ans, cnt);
    cnt = 0;
    for(int i = 0; i <= mxr; i++) {
        if(s[i] == 'B') cnt++;
    }
    ans = min(ans, cnt);
    cnt = 0;
    for(int i = n - 1; i >= mnb; i--) {
        if(s[i] == 'R') cnt++;
    }
    ans = min(ans, cnt);
    cnt = 0;
    for(int i = n - 1; i >= mnr; i--) {
        if(s[i] == 'B') cnt++;
    }
    ans = min(ans, cnt);
    cout << ans;
}