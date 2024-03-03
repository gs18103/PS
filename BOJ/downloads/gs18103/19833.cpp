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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector <int> a(n+2), num;
    vector <vector <ll> > v(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        num.eb(a[i]);
        v[i].eb(0);
    }
    sort(all(num));
    for(int i = 1; i <= n; i++) {
        a[i] = lower_bound(all(num), a[i]) - num.begin() + 1;
        v[a[i]].eb(i);
    }
    for(int i = 1; i <= n; i++) {
        v[i].eb(n+1);
    }

    set <ll> st;
    st.em(0), st.em(n+1);

    ll ans = 0;
    for(int i = n; i >= 1; i--) {
        vector <ll> sum(v[i].size());
        int k = v[i].size() - 2;
        for(int j = k; j >= 1; j--) {
            auto it = st.lower_bound(v[i][j]);
            ll temp = (*it - v[i][j]) * (v[i][j] - max(*prev(it), v[i][j-1]));
            sum[j] = sum[j+1] + temp;
            sum[j] %= mod;
        }
        for(int j = 1; j < k; j++) {
            auto it = st.lower_bound(v[i][j]);
            ll cnt = ((min(*it, v[i][j+1]) - v[i][j]) * (v[i][j] - *prev(it))) % mod;
            if(*it < v[i][j+1]) {
                ans += sum[j+1] * cnt;
                ans %= mod;
            }
            else {
                ans += sum[j+2] * cnt;
                ans %= mod;
                ll base = ((v[i][j] - *prev(it)) * (*it - v[i][j+1])) % mod;
                ll bet = ((v[i][j+1] - v[i][j]) * (v[i][j+1] - v[i][j] + 1) / 2) % mod;
                ans += (base * bet) % mod;
                ans %= mod;
            }
        }

        for(int j = 1; j <= k; j++) {
            st.em(v[i][j]);
        }

    }
    cout << ans;
}