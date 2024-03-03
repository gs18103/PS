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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

vector <int> get_fail(string s) {
    int p = 0, n = s.size();
    vector <int> F(n);
    for(int i = 1; i < n; i++) {
        while(p && s[p] != s[i]) p = F[p-1];
        if(s[p] == s[i]) p++;
        F[i] = p;
    }
    return F;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s;
    cin >> s;
    vector <int> F = get_fail(s);

    for(int i = 0; i < s.size(); i++) {
        if(F[i] && (i + 1) % (i + 1 - F[i]) == 0) {
            cout << i + 1 << ' ' << (i + 1) / (i + 1 - F[i]) << '\n';
        }
    }
}