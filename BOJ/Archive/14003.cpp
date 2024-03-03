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

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

int chk[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    vector <int> a, v, ans;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int u;
        cin >> u;
        a.eb(u);
        chk[i] = lower_bound(all(v), u) - v.begin();
        if(v.empty() || v.back() < u) v.eb(u);
        else {
            auto it = lower_bound(all(v), u);
            *it = u;
        }
    }

    cout << v.size() << '\n';
    int cnt = v.size();
    for(int i = n - 1; i >= 0; i--) {
        if(cnt == 0) break;
        if(chk[i] == cnt - 1) {
            ans.eb(a[i]);
            cnt--;
        }
    }
    while(!ans.empty()) {
        cout << ans.back() << ' ';
        ans.pop_back();
    }
}