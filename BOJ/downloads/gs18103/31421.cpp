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
    cin >> n >> s;
    vector <int> ans;
    if(n == 1) {
        if(s[0] == 'B') cout << "-1\n";
        else cout << "0\n";
        return 0;
    }
    else if(s[n-1] == 'W') {
        for(int i = 0; i + 1 < n; i++) {
            if(s[i] != s[i+1]) ans.eb(i+1);
        }
    }
    else {
        for(int i = 0; i + 1 < n; i++) {
            if(s[i] != s[i+1]) ans.eb(i+1);
        }
        if(ans.size() < 2) {
            cout << "-1\n";
            return 0;
        }
        swap(ans[ans.size()-1], ans[ans.size()-2]);
    }

    cout << ans.size() << '\n';
    for(int i : ans) cout << i << '\n';
}