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
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m), c(n+m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int idx1 = 0, idx2 = 0, idx = 0;
    while(idx1 < n && idx2 < m) {
        if(a[idx1] < b[idx2]) c[idx++] = a[idx1++];
        else c[idx++] = b[idx2++];
    }
    while(idx1 < n) c[idx++] = a[idx1++];
    while(idx2 < m) c[idx++] = b[idx2++];
    for(auto i : c) cout << i << ' ';
}