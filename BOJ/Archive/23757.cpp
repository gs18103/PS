#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex <double> cpx;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    priority_queue <int> pq;
    for(int i = 1; i <= n; i++) {
        int u; cin >> u;
        pq.em(u);
    }
    for(int i = 1; i <= m; i++) {
        int u; cin >> u;
        int x = pq.top();
        pq.pop();
        if(x < u) return cout << 0, 0;
        pq.em(x - u);
    }
    cout << 1;
}