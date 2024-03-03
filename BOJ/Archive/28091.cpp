#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll ccw(pll a, pll b, pll c) {
    return (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
}

ll cal(vector <pll> p) {
    int n = p.size();
    sort(all(p));
    pll base = p[0];
    sort(p.begin()+1, p.end(), [base](pll a, pll b) {
        return ccw(base, a, b) > 0;
    });

    vector <pll> ch;
    for(int i = 0; i < n; i++) {
        while(ch.size() >= 2 && ccw(ch[ch.size()-2], ch[ch.size()-1], p[i]) < 0) ch.pop_back();
        ch.eb(p[i]);
    }

    n = ch.size();
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int p1 = i, p2 = i + 1;
        for(int j = i + 1; j < n; j++) {
            while(p1 < j && ccw(ch[i], ch[p1], ch[j]) < ccw(ch[i], ch[p1+1], ch[j])) p1++;
            while((p2 + 1) % n != i && ccw(ch[j], ch[p2], ch[i]) < ccw(ch[j], ch[(p2+1)%n], ch[i])) p2 = (p2+1) % n;
            ans = max(ans, ccw(ch[i], ch[p1], ch[j]) + ccw(ch[j], ch[p2], ch[i]));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed;
    cout.precision(4);

    int n, m;
    cin >> n >> m;
    vector <pll> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i].fi >> p[i].se;
    }
    p.eb(0, m);
    p.eb(0, -m);
    p.eb(m, 0);
    p.eb(-m, 0);

    ll S = cal(p);
    cout << (S / 16.0) * S;
}