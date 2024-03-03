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
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <pii> arr(n+1);
    vector <int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    vector <vector <ll> > d(5*n+1);
    map <int, set <int> > Y;
    set <pii> st;
    for(int i = 1; i <= 5 * n; i++) {
        d[i].resize(5 * n + 1);
    }
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }

    for(int i = 1; i <= n; i++) {
        st.em(arr[i]);
        Y[arr[i].se].em(arr[i].fi);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            d[i][j] = d[j][i] = INF;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(abs(arr[i].fi - arr[(i%n)+1].fi) + abs(arr[i].se - arr[(i%n)+1].se) == 1) d[i][(i%n)+1] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 4; j++) {
            int x = arr[i].fi + dx[j];
            int y = arr[i].se + dy[j];
            if(st.find({x, y}) == st.end()) {
                arr.eb(x, y), st.em(x, y), Y[y].em(x);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = n + 1; j < arr.size(); j++) {
            if(abs(arr[i].fi - arr[j].fi) + abs(arr[i].se - arr[j].se) == 1) {
                d[i][j] = d[j][i] = 1;
            }
            else {
                d[i][j] = d[j][i] = INF;
            }
        }
    }
    for(int i = n + 1; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            bool flag1 = false, flag2 = false;
            for(int k = 1; k < arr.size(); k++) {
                if(k == i || k == j) continue;
                if(arr[k].fi == arr[i].fi) {
                    if(arr[k].se > arr[i].se && arr[k].se < arr[j].se) flag1 = true;
                    if(arr[k].se < arr[i].se && arr[k].se > arr[j].se) flag1 = true;
                }
                if(arr[k].se == arr[i].se) {
                    if(arr[k].fi > arr[i].fi && arr[k].fi < arr[j].fi) flag2 = true;
                    if(arr[k].fi < arr[i].fi && arr[k].fi > arr[j].fi) flag2 = true;
                }
                if(arr[k].fi == arr[j].fi) {
                    if(arr[k].se > arr[i].se && arr[k].se < arr[j].se) flag2 = true;
                    if(arr[k].se < arr[i].se && arr[k].se > arr[j].se) flag2 = true;
                }
                if(arr[k].se == arr[j].se) {
                    if(arr[k].fi > arr[i].fi && arr[k].fi < arr[j].fi) flag1 = true;
                    if(arr[k].fi < arr[i].fi && arr[k].fi > arr[j].fi) flag1 = true;
                }
            }
            if(flag1 && flag2) d[i][j] = d[j][i] = INF;
            else d[i][j] = d[j][i] = abs(arr[i].fi - arr[j].fi) + abs(arr[i].se - arr[j].se);
        }
    }
    for(int k = n + 1; k < arr.size(); k++) {
        for(int i = 1; i < arr.size(); i++) {
            for(int j = 1; j < arr.size(); j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    ll ans = d[n][1];
    for(int i = 1; i < n; i++) {
        ans += d[i][i+1];
    }
    if(ans < INF) cout << ans;
    else cout << -1;
}