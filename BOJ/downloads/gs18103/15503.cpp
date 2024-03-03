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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector <pii> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].fi;
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i].se;
    }
    sort(all(v));

    ll ans = 1, mod = 1e9+7;
    map <int, int> mp;
    mp[0] = 1;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        int k;
        for(k = i; k < n && v[i].fi == v[k].fi; k++) ;
        for(int j = i; j < k; j++) {
            if(v[j].se - v[j].fi == 0) {
                if(flag) {
                    cout << 0;
                    return 0;
                }
                flag = true;
            }
            if(mp.find(v[j].se - v[j].fi) == mp.end()) {
                cout << 0;
                return 0;
            }
            ans *= mp[v[j].se-v[j].fi];
            ans %= mod;
        }
        for(int j = i; j < k; j++) {
            mp[v[j].se]++;
        }
        i = k - 1;
    }
    cout << ans << '\n';
}