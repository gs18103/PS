#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 55;
const int INF = 1e9;
const ll LINF = 1e18;

string s[MAX];
pii pos[1<<8];

void solve(int n, int m) {
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '_') continue;
            pos[s[i][j]] = {i, j};
        }
    }

    string t;
    cin >> t;
    int x = 0, y = 0, ans = 0;
    for(int i = 0; i < t.size(); i++) {
        ans += abs(x - pos[t[i]].fi) + abs(y - pos[t[i]].se);
        x = pos[t[i]].fi, y = pos[t[i]].se;
    }
    cout << ans + t.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    while(n != 0 && m != 0) {
        solve(n, m);
        cin >> n >> m;
    }
}