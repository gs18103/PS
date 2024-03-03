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
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++) {
        int u; cin >> u;
        if(v.empty() || v.back() < u) v.eb(u);
        v[lower_bound(all(v), u)-v.begin()] = u;
    }
    cout << v.size();
}