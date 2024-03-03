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
typedef pair <int, ll> pil;

const int INF = 1e9;
const ll LINF = 1e18;

int cnt[101010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u; cin >> u;
        cnt[u]++;
    }

    for(int i = 1; i <= 100000; i++) {
        if(cnt[i] > (n + 1) / 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}