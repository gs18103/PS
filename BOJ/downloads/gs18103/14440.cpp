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

const int MAX = 1010101;
const int INF = 1e9;
const ll LINF = 1e18;

int mat[2][2], temp[2][2], res[2][2];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int x, y, a0, a1;
    ll n;
    cin >> x >> y >> a0 >> a1 >> n;
    mat[0][1] = 1;
    mat[1][0] = y;
    mat[1][1] = x;
    res[0][0] = res[1][1] = 1;
    while(n > 0) {
        if(n & 1) {
            temp[0][0] = mat[0][0] * res[0][0] + mat[0][1] * res[1][0];
            temp[0][1] = mat[0][0] * res[0][1] + mat[0][1] * res[1][1];
            temp[1][0] = mat[1][0] * res[0][0] + mat[1][1] * res[1][0];
            temp[1][1] = mat[1][0] * res[0][1] + mat[1][1] * res[1][1];
            res[0][0] = temp[0][0] % 100;
            res[0][1] = temp[0][1] % 100;
            res[1][0] = temp[1][0] % 100;
            res[1][1] = temp[1][1] % 100;
        }
        temp[0][0] = mat[0][0] * mat[0][0] + mat[0][1] * mat[1][0];
        temp[0][1] = mat[0][0] * mat[0][1] + mat[0][1] * mat[1][1];
        temp[1][0] = mat[1][0] * mat[0][0] + mat[1][1] * mat[1][0];
        temp[1][1] = mat[1][0] * mat[0][1] + mat[1][1] * mat[1][1];
        mat[0][0] = temp[0][0] % 100;
        mat[0][1] = temp[0][1] % 100;
        mat[1][0] = temp[1][0] % 100;
        mat[1][1] = temp[1][1] % 100;
        n >>= 1;
    }
    int ans = (res[0][0] * a0 + res[0][1] * a1) % 100;
    cout << ans / 10 << ans % 10;
}