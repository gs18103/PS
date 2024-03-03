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

const int MAX = 101;
const int INF = 1e9;
const ll LINF = 1e18;

int d[MAX][MAX];
bool chk[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }

    vector <pair <pii, int> > E;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            bool flag = false;
            for(int k = 1; k <= n; k++) {
                if(k == i || k == j) continue;
                if(d[i][j] > d[i][k] + d[k][j]) {
                    return !(cout << 0);
                }
                if(d[i][j] == d[i][k] + d[k][j]) {
                    flag = true;
                }
            }
            if(!flag) E.eb(make_pair(i, j), d[i][j]), chk[i][j] = true;
        }
    }

    if(E.size() > m) return !(cout << 0);

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(chk[i][j]) continue;
            if(E.size() == m) break;
            E.eb(make_pair(i, j), 500);
        }
        if(E.size() == m) break;
    }

    cout << "1\n";
    for(auto i : E) cout << i.fi.fi << ' ' << i.fi.se << ' ' << i.se << '\n';
}