#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 303030;
const int INF = 1e9;
const ll LINF = 1e18;
const ll mod = 998244353;

int A[MAX];
set <pii> cs;
set <int> is;
vector <int> v[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        if(v[A[i]].empty()) is.em(i);
        v[A[i]].eb(i);
    }
    for(int i = 1; i <= n; i++) {
        reverse(all(v[i]));
        if(v[i].size() > (n + 1) / 2) return !(cout << "-1");
        cs.em(v[i].size(), i);
    }

    int pre = -1;
    for(int i = 1; i <= n; i++) {
        if(cs.rbegin()->fi == (n + 3 - i) / 2) {
            pii tmp = *cs.rbegin();
            cout << v[tmp.se].back() << ' ';
            pre = tmp.se;
            cs.erase(tmp);
            is.erase(v[tmp.se].back());
            v[tmp.se].pop_back();
            tmp.fi--;
            if(tmp.fi > 0) {
                is.em(v[tmp.se].back());
                cs.em(tmp);
            }
        }
        else {
            int x = *is.begin();
            if(A[x] == pre) x = *next(is.begin());
            cout << x << ' ';
            pre = A[x];
            pii tmp = {v[A[x]].size(), A[x]};
            cs.erase(tmp);
            is.erase(x);
            v[A[x]].pop_back();
            tmp.fi--;
            if(tmp.fi > 0) {
                is.em(v[A[x]].back());
                cs.em(tmp);
            }
        }
    }
}