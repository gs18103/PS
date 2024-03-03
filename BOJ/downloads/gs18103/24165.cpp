#include <bits/stdc++.h>
#define fi first
#define se second
#define em emplace

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll ccw(pll a, pll b) {
    return a.fi * b.se - a.se * b.fi;
}

pll mod(pll x) {
    ll g = __gcd(abs(x.fi), abs(x.se));
    if(x.se < 0) g = -g;
    return pll(x.fi / g, x.se / g);
}

pll divide(pll a, pll b) {
    return mod(pll(a.fi * b.se, a.se * b.fi));
}

pll mul(pll a, pll b) {
    return mod(pll(a.fi * b.fi, a.se * b.se));
}

pll sub(pll a, pll b) {
    return mod(pll(a.fi * b.se - a.se * b.fi, a.se * b.se));
}

pair <pll, pll> get_cross(pll a1, pll a2, pll b1, pll b2) {
    pll va = pll(a2.se - a1.se, - a2.fi + a1.fi);
    pll vb = pll(b2.se - b1.se, - b2.fi + b1.fi);
    va = mod(va), vb = mod(vb);
    ll ca = va.fi * a1.fi + va.se * a1.se;
    ll cb = vb.fi * b1.fi + vb.se * b1.se;
    pll x, y;
    if(va.se == 0) {
        x = pll(ca, va.fi); x = mod(x);
        y = sub(pll(cb, vb.se), mul(vb, x));
    }
    else {
        if(vb.se == 0) { x = pll(cb, vb.fi); x = mod(x); }
        else x = divide(sub(pll(ca, va.se), pll(cb, vb.se)), sub(va, vb));
        y = sub(pll(ca, va.se), mul(va, x));
    }
    
    x = mod(x), y = mod(y);
    return pair <pll, pll> (x, y);
}

bool parallel(pll a1, pll a2, pll b1, pll b2) {
    pll va = pll(a2.fi - a1.fi, a2.se - a1.se);
    pll vb = pll(b2.fi - b1.fi, b2.se - b1.se);
    return ccw(va, vb) == 0;
}

bool isin(pll v, pll x, ll c) {
    return v.fi * x.fi + v.se * x.se == c;
}

bool same(pll a1, pll a2, pll b1, pll b2) {
    pll va = pll(a2.se - a1.se, - a2.fi + a1.fi);
    ll ca = va.fi * a1.fi + va.se * a1.se;
    if(isin(va, b1, ca) && isin(va, b2, ca)) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector <pll> P(n), Q(n);
    
    
    for(int i = 0; i < n; i++) {
        cin >> P[i].fi >> P[i].se >> Q[i].fi >> Q[i].se;
    }
    
    int ans = 2;
    for(int i = 1; i < n; i++) {
        set <pair <pll, pll>> s;
        bool flag = false;
        for(int j = 0; j < i; j++) {
            if(same(P[i], Q[i], P[j], Q[j])) flag = true;
            if(parallel(P[i], Q[i], P[j], Q[j])) continue;
            s.emplace(get_cross(P[i], Q[i], P[j], Q[j]));
        }
        if(!flag) ans += s.size() + 1;
    }
    
    cout << ans;

    return 0;
}
