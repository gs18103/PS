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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    set <pii> st;
    vector <pii> num;
    for(int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        st.em(i, u);
        num.eb(u, i);
    }
    sort(all(num));
    ll ans = 0;
    for(int i = 0; i < num.size() - 1; i++) {
        auto it = st.find({num[i].se, num[i].fi});
        if(it == st.begin()) ans += next(it)->se - it->se;
        else if(next(it) == st.end()) ans += prev(it)->se - it->se;
        else ans += min(next(it)->se - it->se, prev(it)->se - it->se);
        st.erase(it);
    }
    cout << ans;
}