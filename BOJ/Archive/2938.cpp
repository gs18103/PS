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

const int MAX = 101;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+9;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    vector <int> z, o, t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int u; cin >> u;
        if(u % 3 == 0) z.eb(u);
        if(u % 3 == 1) o.eb(u);
        if(u % 3 == 2) t.eb(u);
    }
    if(z.size() == 0 && o.size() > 0 && t.size() > 0) return !(cout << "-1");
    if(z.size() > o.size() + t.size() + 1) return !(cout << "-1");
    if(z.size() == 0) {
        for(auto i : o) cout << i << ' ';
        for(auto i : t) cout << i << ' ';
        return 0;
    }

    vector <int> ans;
    ans.eb(z.back());
    z.pop_back();
    while(!z.empty() && !o.empty()) {
        ans.eb(o.back());
        ans.eb(z.back());
        o.pop_back();
        z.pop_back();
    }
    while(!z.empty() && !t.empty()) {
        ans.eb(t.back());
        ans.eb(z.back());
        t.pop_back();
        z.pop_back();
    }
    for(auto i : o) cout << i << ' ';
    for(auto i : ans) cout << i << ' ';
    for(auto i : t) cout << i << ' ';
}