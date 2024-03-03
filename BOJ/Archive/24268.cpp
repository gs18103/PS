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

    ll n, d;
    cin >> n >> d;
    string s;
    while(n > 0) {
        s = (char)((n % d) + '0') + s;
        n /= d;
    }
    if(s.size() > d) return !(cout << -1);
    while(s.size() < d) {
        s = "0" + s;
    }

    vector <int> p(d);
    int f = 1;
    for(int i = 0; i < d; i++) p[i] = i, f *= i + 1;
    swap(p[0], p[1]);
    string ans;
    for(int i = 0; i < f; i++) {
        if(p[0] == 0) break;
        string t;
        for(int j = 0; j < d; j++) {
            t += (char)(p[j] + '0');
        }
        if(t > s) {
            if(ans == "") ans = t;
            else if(ans > t) ans = t;
        }
        next_permutation(all(p));
    }
    if(ans == "") cout << "-1";
    else {
        ll nans = 0, e = 1;
        while(!ans.empty()) {
            nans += (ans.back() - '0') * e;
            e *= d;
            ans.pop_back();
        }
        cout << nans;
    }
}