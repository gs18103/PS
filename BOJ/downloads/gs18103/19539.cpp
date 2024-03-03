#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, odd = 0, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        if(u & 1) odd++;
        sum += u;
    }
    if(sum % 3 != 0) {
        cout << "NO";
        return 0;
    }
    if(odd > sum / 3) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}   