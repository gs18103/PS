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

pll add(pll a, pll b) {
    return {a.fi * b.se + a.se * b.fi, a.se * b.se};
}

pll frac(pll a, pll b) {
    return {a.fi * b.se, a.se * b.fi};
}

pll get(string s) {
    if(s.size() == 1) {
        if(s[0] < '0' || s[0] > '9') return {0, 0};
        return {s[0]-'0', 1};
    }
    if(s[0] != '(') return {0, 0};
    if(s[s.size()-1] != ')') return {0, 0};

    string a, b, c;
    int num = 0, i = 1;
    for(; i < s.size() - 1; i++) {
        if(s[i] == '(') num++;
        else if(s[i] == ')') num--;
        a += s[i];
        if(num < 0) return {0, 0};
        if(num == 0) {
            i++;
            break;
        }
    }
    for(; i < s.size() - 1; i++) {
        if(s[i] == '(') num++;
        else if(s[i] == ')') num--;
        b += s[i];
        if(num < 0) return {0, 0};
        if(num == 0) {
            i++;
            break;
        }
    }
    for(; i < s.size() - 1; i++) {
        if(s[i] == '(') num++;
        else if(s[i] == ')') num--;
        c += s[i];
        if(num < 0) return {0, 0};
        if(num == 0) {
            i++;
            break;
        }
    }

    if(i != s.size() - 1) return {0, 0};
    pll va = get(a), vb = get(b), vc = get(c);
    if(va.se == 0 || vb.se == 0 || vc.se == 0) return {0, 0};
    return add(va, frac(vb, vc));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; 
    string s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        s += tmp;
    }

    pll ans = get(s);
    if(ans.se == 0) cout << -1 << endl;
    else {
        ll g = __gcd(ans.fi, ans.se);
        ans.fi /= g, ans.se /= g;
        cout << ans.fi << ' ' << ans.se << endl;
    }
}