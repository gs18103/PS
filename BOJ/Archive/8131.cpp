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
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

ll arr[MAX][MAX], sumi[MAX][MAX], sumj[MAX][MAX];
bool chki[MAX][MAX], chkj[MAX][MAX];
int ans = 0, n, m, k;

void f_i(int s, int e, int l, int r) {
    if(l > r) return;
    if(s > e) {
        ans = max(ans, r - l + 1);
        return;
    }
    chki[l][r] = true;
    if(sumi[s][r] - sumi[s][l-1] <= k) f_i(s+1, e, l, r);
    else if(sumi[e][r] - sumi[e][l-1] <= k) f_i(s, e-1, l, r);
    else {
        if(sumj[e][l] - sumj[s-1][l] <= k) {
            if(!chki[l+1][r]) f_i(s, e, l+1, r);
        }
        if(sumj[e][r] - sumj[s-1][r] <= k) {
            if(!chki[l][r-1]) f_i(s, e, l, r-1);
        }
    }
}

void f_j(int s, int e, int l, int r) {
    if(l > r) return;
    if(s > e) {
        ans = max(ans, r - l + 1);
        return;
    }
    chkj[l][r] = true;
    if(sumj[r][s] - sumj[l-1][s] <= k) f_j(s+1, e, l, r);
    else if(sumj[r][e] - sumj[l-1][e] <= k) f_j(s, e-1, l, r);
    else {
        if(sumi[l][e] - sumi[l][s-1] <= k) {
            if(!chkj[l+1][r]) f_j(s, e, l+1, r);
        }
        if(sumi[r][e] - sumi[r][s-1] <= k) {
            if(!chkj[l][r-1]) f_j(s, e, l, r-1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> k >> m >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            sumi[i][j] = sumi[i][j-1] + arr[i][j];
            sumj[i][j] = sumj[i-1][j] + arr[i][j];
        }
    }
    f_i(1, n, 1, m), f_j(1, m, 1, n);
    cout << n + m - ans;
}