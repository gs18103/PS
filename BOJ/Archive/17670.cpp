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

const int MAX = 2020;
const int INF = (1 << 30) - 1;
const ll LINF = 1LL << 60;

int n, k, p[MAX];
ll v[MAX][MAX], sum[MAX][MAX];
pll X[MAX], dv[MAX][MAX];
bool chk[MAX];

bool small(pll x, pll y) {
    if(x.fi / x.se == y.fi / y.se) return (x.fi % x.se) * y.se > (y.fi % y.se) * x.se;
    else return x.fi / x.se > y.fi / y.se;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("03-02.txt", "r", stdin);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            cin >> v[i][j];
            sum[i][j] = sum[i][j-1] + v[i][j];
        }
        int idx = 0;
        for(int j = 1; j < n; j++) {
            while(sum[i][idx+1] * n <= sum[i][k] * j && idx < k) idx++;
            dv[i][j] = make_pair(sum[i][k] * j - sum[i][idx] * n, n * v[i][idx+1]);
            dv[i][j].fi += dv[i][j].se * idx;
        }
        dv[i][n] = make_pair(k, 1);
    }
    for(int i = 1; i <= n; i++) {
        int idx = -1;
        for(int j = 1; j <= n; j++) {
            if(chk[j]) continue;
            if(idx == -1 || small(dv[idx][i], dv[j][i])) {
                idx = j;
            }
        }
        chk[idx] = true;
        p[i] = idx;
        X[i] = dv[idx][i];
    }

    for(int i = 1; i < n; i++) {
        cout << X[i].fi << ' ' << X[i].se << endl;
    }
    for(int i = 1; i <= n; i++) {
        cout << p[i] << ' ';
    }
}