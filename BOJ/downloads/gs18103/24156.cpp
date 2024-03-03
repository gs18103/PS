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

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <pii> v;
    int sum = 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i != 0) continue;
        v.eb(i, 0);
        while(n % i == 0) {
            v.back().se++;
            sum++;
            n /= i;
        }
    }
    if(n != 1) v.eb(n, 1), sum++;
    if(v.back().fi > 100) cout << v.back().fi;
    else {
        for(int i = 2; i <= 100; i++) {
            for(pii &j : v) {
                int k = i;
                while(k % j.fi == 0 && j.se > 0) {
                    j.se--;
                    sum--;
                    k /= j.fi;
                }
            }
            if(sum == 0) return !(cout << i);
        }
    }
}