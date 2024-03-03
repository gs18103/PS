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

const int INF = 1e9;
const ll LINF = 1e18;

struct G {
    ll w, c; int idx;
    G(ll _w, ll _c, int _idx) : w(_w), c(_c), idx(_idx) {}
};

void solve() {
    int n; ll w;
    cin >> n >> w;
    vector <G> b, s;
    for(int i = 0; i < n; i++) {
        ll tw, tc; cin >> tw >> tc;
        if(tw <= w / 2) s.eb(tw, tc, i + 1);
        else if(tw <= w) b.eb(tw, tc, i + 1);
    }
    sort(all(b), [](G x, G y) {
        return x.w < y.w;
    });
    sort(all(s), [](G x, G y) {
        if(x.c * y.w == y.c * x.w) return x.c > y.c;
        return x.c * y.w > y.c * x.w;
    });

    w = (3 * w) / 2;
    int idx = 0, aidx = -1;
    ll ans = 0, sum = 0, csum = 0;
    while(idx < s.size() && sum + s[idx].w <= w) {
        sum += s[idx].w;
        csum += s[idx].c;
        idx++;
    }
    ans = csum;
    for(int i = 0; i < b.size(); i++) {
        while(idx > 0 && sum + b[i].w > w) {
            idx--;
            sum -= s[idx].w;
            csum -= s[idx].c;
        }
        if(ans < csum + b[i].c) {
            ans = csum + b[i].c;
            aidx = i;
        }
    }
    
    if(aidx < 0) {
        while(idx < s.size() && sum + s[idx].w <= w) {
            sum += s[idx].w;
            idx++;
        }
        cout << idx << '\n';
        for(int i = 0; i < idx; i++) {
            cout << s[i].idx << ' ';
        }
        cout << '\n';
    }
    else {
        while(idx < s.size() && sum + s[idx].w + b[aidx].w <= w) {
            sum += s[idx].w;
            idx++;
        }
        cout << idx + 1 << '\n';
        cout << b[aidx].idx << ' ';
        for(int i = 0; i < idx; i++) {
            cout << s[i].idx << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}