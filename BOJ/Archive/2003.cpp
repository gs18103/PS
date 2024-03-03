#include <bits/stdc++.h>

using namespace std;

int a[10101];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1, r = 1, sum = a[1], cnt = 0;
    while(r <= n) {
        if(l > r) {
            r = l;
            sum = a[l];
            continue;
        }
        if(sum == m) cnt++;
        if(sum >= m) {
            sum -= a[l];
            l++;
        }
        else {
            r++;
            sum += a[r];
        }
    }
    cout << cnt;
}