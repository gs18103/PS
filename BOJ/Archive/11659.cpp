#include <bits/stdc++.h>

using namespace std;

long long sum[101010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        long long u; cin >> u;
        sum[i] = sum[i-1] + u;
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);
        cout << sum[r] - sum[l-1] << '\n';
    }
}