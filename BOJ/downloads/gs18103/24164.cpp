#include <bits/stdc++.h>
#define fi first
#define se second
#define em emplace

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

struct DSU {
    vector <int> p;
    DSU(int n) {
        p.resize(n+1);
        for(int i = 1; i <= n; i++) p[i] = i;
    }
    
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    
    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if(x > y) swap(x, y);
        if(x == y) return false;
        p[y] = x;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    int cnt = 0;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if(dsu.uni(u, v)) cnt++;
    }
    cout << n - cnt - 1;

    return 0;
}
