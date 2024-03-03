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
const ll mod = 1e9+7;

int ans[MAX], a[MAX], b[MAX], mxl[MAX], mxr[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    sort(a+1, a+n+1), sort(b+1, b+n+1);
    for(int i = 1; i <= n; i++) {
        mxl[i] = max(mxl[i-1], abs(a[i] - b[i]));
    }
    for(int i = n; i > 0; i--) {
        mxr[i] = max(mxr[i+1], abs(a[i] - b[i]));
    }

    int lb = 0, ub = INF + 10;
    while(lb < ub) {
        int m = (lb + ub) >> 1;
        int l = n, r = 1;
        for(int i = 1; i <= n; i++) {
            if(mxl[i] > m) {
                l = i;
                break;
            }
        }
        for(int i = n; i > 0; i--) {
            if(mxr[i] > m) {
                r = i;
                break;
            }
        }
        bool flag1 = true, flag2 = true;
        for(int i = l; i < r; i++) {
            if(abs(a[i] - b[i+1]) > m) flag1 = false;
            if(abs(a[i+1] - b[i]) > m) flag2 = false;
        }
        if(flag1 || flag2) ub = m;

        else lb = m + 1;
    }
    int l = n, r = 1;
    for(int i = 1; i <= n; i++) {
        if(mxl[i] > lb) {
            l = i;
            break;
        }
    }
    for(int i = n; i > 0; i--) {
        if(mxr[i] > lb) {
            r = i;
            break;
        }
    }
    bool flag1 = true, flag2 = true;
    for(int i = l; i < r; i++) {
        if(abs(a[i] - b[i+1]) > lb) flag1 = false;
        if(abs(a[i+1] - b[i]) > lb) flag2 = false;
    }
    if(flag2) {
        for(int i = r - 1; i > 0; i--) {
            if(abs(a[i+1] - b[i]) > lb) {
                cout << a[i + 1];
                return 0;
            }
        }
        cout << a[1];
    }
    else cout << a[r];
}