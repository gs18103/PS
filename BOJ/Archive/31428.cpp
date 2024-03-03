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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    string s;
    cin >> n;
    vector <string> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(t[i] == s) ans++;
    }
    cout << ans << '\n';
}