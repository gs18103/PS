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

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int len = 0, ans = 0;
    bool flag = false;
    for(int i = 0; i < m; i++) {
        if(flag) {
            if(s[i] == 'O') len++, flag = false;
            else {
                ans += max(0, len / 2 - n + 1);
                len = 1;
            }
        }
        else {
            if(s[i] == 'I') len++, flag = true;
            else {
                ans += max(0, len / 2 - n);
                len = 0;
            }
        }
    }
    ans += max(0, (len - 1) / 2 - n + 1);
    cout << ans;
}