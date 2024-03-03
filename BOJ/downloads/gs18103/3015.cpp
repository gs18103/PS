#include <bits/stdc++.h>

using namespace std;

int a[505050];
int b[505050];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int st = n + 1, ed = n + 1;
    long long ans = 0;
    for(int i = n; i >= 1; i--) {
        auto u = upper_bound(b + st, b + ed, a[i]);
        if(u == b + ed) ans += ed - st;
        else ans += u - (b + st) + 1;
        while(st < ed) {
            if(a[i] > b[st]) st++;
            else break;
        }
        b[--st] = a[i];
    }
    cout << ans;
}