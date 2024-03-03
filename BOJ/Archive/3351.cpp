#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef pair <int, int> pii;

const int MAX = 101010;

vector <int> g[MAX], C[MAX];
int num[MAX], low[MAX], cnt = 0, ans = 0;

void dfs(int x, int pa) {
    low[x] = num[x] = ++cnt;
    bool flag = false;
    for(auto i : g[x]) {
        if(i == pa && !flag) {
            flag = true;
            continue;
        }
        if(num[i] != 0) low[x] = min(low[x], num[i]);
        else if(num[i] == 0) {
            dfs(i, x);
            low[x] = min(low[x], low[i]);
        }
    }
    for(auto i : g[x]) {
        if(i == pa) continue;
        if(low[i] > num[x]) ans++;
    }
}

map <pii, int> l;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n - 2; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        C[d].eb(i);
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
        if(l.find({a, b}) != l.end()) {
            int u = l[{a, b}];
            g[u].eb(i), g[i].eb(u);
        }
        else l[{a, b}] = i;
        if(l.find({b, c}) != l.end()) {
            int u = l[{b, c}];
            g[u].eb(i), g[i].eb(u);
        }
        else l[{b, c}] = i;
        if(l.find({a, c}) != l.end()) {
            int u = l[{a, c}];
            g[u].eb(i), g[i].eb(u);
        }
        else l[{a, c}] = i;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < C[i].size(); j++) {
            g[C[i][j]].eb(C[i][j-1]), g[C[i][j-1]].eb(C[i][j]);
        }
    }
    dfs(1, 0);
    cout << ans;
}