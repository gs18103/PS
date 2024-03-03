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

vector <int> get_fail(string t) {
    int p = 0, n = t.size();
    vector <int> F(n);
	for(int i = 1; i < n; i++) {
		while(p > 0 && t[i] != t[p]) p = F[p-1];
		if(t[i] == t[p]) p++;
		F[i] = p;
	}
    return F;
}

bool KMP(string s, string t) {
    int p = 0, n = s.size();
    vector <int> F = get_fail(t);
	for(int i = 0; i < n; i++) {
		while(p > 0 && s[i] != t[p]) p = F[p-1];
		if(s[i] == t[p]) p++;
        if(p == t.size()) return true;
	}
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string a, b, s;
    cin >> a >> b >> s;
    if(KMP(a, s) && KMP(b, s)) cout << "YES";
    else cout << "NO";
}