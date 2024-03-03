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

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int x; string s;
    cin >> x >> s;
    int num = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'W') num = num + 1;
        else num = num - 1;
        if(abs(num) == x + 2) return cout << i - 1, 0;
    }
    if(abs(num) > x)cout << s.size() - 1;
    else cout << s.size();
}