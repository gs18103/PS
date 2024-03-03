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

const int INF = 1 << 30;
const ll LINF = 1LL << 62;
const int MAX = 101010;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q, u = 0, d = 0, l = 0, r = 0;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'U') u++;
        if(s[i] == 'D') d++;
        if(s[i] == 'L') l++;
        if(s[i] == 'R') r++;
    }

    while(q--) {
        int x, y; cin >> x >> y;
        if((abs(x)+abs(y)) % 2 != n % 2 || abs(x) + abs(y) > n) {
            cout << "-1\n";
            continue;
        } 
        int ans = 0;
        bool chk = false;
        if(u + d < abs(y)) {
            swap(x, y);
            swap(l, d);
            swap(r, u);
            chk = true;
        }

        if(l + r < abs(x)) {
            if(x < 0) ans += r;
            else ans += l;
            int dx = abs(x) - l - r;
            ans += abs(dx);
            if(abs(u - d - y) > abs(dx)) ans += (abs(u - d - y) - abs(dx)) / 2;
        }
        else {
            if(abs(r - l - x) % 2 == 0) {
                ans = abs(r - l - x) / 2 + abs(u - d - y) / 2;
            }
            else {
                ans = abs(r - l - x) / 2 + abs(u - d - y) / 2 + 1;
            }
        }
        cout << ans << '\n';
        if(chk) {
            swap(l, d);
            swap(r, u);
        }
    }
}