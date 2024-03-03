#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n;
    cin >> n;
    int m;
    cin >> m;

    ll sum = 0, mx = 0;
    ll len = 0;
    for(int i = 0; i < m; i++) {
        string s; ll k;
        cin >> s >> k;
        ll tmx = 0, num = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == 'F') num++;
            else num--;
            tmx = max(tmx, num);
        }
        mx = max(mx, sum + max(0LL, num) * (k - 1) + tmx);
        sum += num * k;
    }
    if(sum < 0) cout << "-1\n";
    else cout << max(0LL, mx - 1 - sum) << endl;
}