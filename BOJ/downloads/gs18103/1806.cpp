#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, s;
    cin >> n >> s;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int p = 1, sum = 0, ans = 1e9;
    for(int i = 1; i <= n; i++) {
        sum += a[i];
        while(sum >= s) {
            ans = min(ans, i - p + 1);
            sum -= a[p];
            p++;
        }
    }
    cout << (ans <= n ? ans : 0);
}