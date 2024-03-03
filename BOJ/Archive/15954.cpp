#include <bits/stdc++.h>

using namespace std;

long long arr[505], sq[505], sum[505], sqsum[505];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout << fixed; cout.precision(8);

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        sq[i] = arr[i] * arr[i];
    }
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + arr[i];
        sqsum[i] = sqsum[i-1] + sq[i];
    }

    long double ans = 10000000.0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + k - 1; j <= n; j++) {
            long double res, mi;
            res = (long double)(sqsum[j] - sqsum[i-1]) / (j - i + 1);
            mi = (long double)(sum[j] - sum[i-1]) / (j - i + 1);
            res -= mi * mi;
            ans = min(ans, sqrt(res));
        }
    }
    cout << ans;
}