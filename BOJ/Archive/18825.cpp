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

ll count(ll x, ll d) {
    ll cnt = 0;
    for(ll i = d; i <= x; i *= d) {
        cnt += x / i;
    }
    return cnt;
}

int poss[MAX];
bool chk[MAX];
int pcnt[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll f, s, m;
    cin >> s >> f >> m;

    vector <ll> p;
    for(ll i = 2; i <= m; i++) {
        if(chk[i]) continue;
        p.eb(i);
        for(ll j = i * i; j <= m; j += i) {
            chk[j] = true;
        }
    }

    vector <ll> cnt;
    for(auto x : p) {
        cnt.eb(count(s + f, x) - count(s, x) - count(f, x));
    }
    for(int i = 0; i < p.size(); i++) {
        for(ll j = p[i]; j <= m; j *= p[i]) {
            for(ll k = j; k <= m; k += j) {
                pcnt[k]++;
            }
        }
        for(ll j = p[i]; j <= m; j += p[i]) {
            if(pcnt[j] <= cnt[i] && poss[j] <= 1) poss[j] = 1;
            else poss[j] = 2;
            pcnt[j] = 0;
        }
    }
    poss[1] = 1;
    for(int i = m; i >= 1; i--) {
        if(poss[i] == 1) return !(cout << i);
    }
}