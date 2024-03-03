#include <bits/stdc++.h>
#define eb emplace_back

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> p(n+1), sz(n+1, 1), cnt(n+1);
    for(int i = 2; i <= n; i++) {
        cin >> p[i];
    }
    for(int i = n; i >= 1; i--) {
        cnt[sz[i]]++;
        sz[p[i]] += sz[i];
    }
    for(int i = n; i >= 1; i--) {
        if(n % i != 0) continue;
        int sum = 0;
        for(int j = i; j <= n; j += i) {
            sum += cnt[j];
        }
        if(sum == n / i) cout << n / i << ' ';
    }

    return 0;
}