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

const int MAX = 202020;
const int INF = 1e9;
const ll LINF = 9e18;

int c[MAX], d[MAX];
vector <int> g[MAX];
bool chk[MAX], chk2[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }

    int lb = 1, ub = n;
    while(lb < ub) {
        int m = (lb + ub + 1) / 2;
        for(int i = 1; i <= n; i++) chk[i] = false;
        for(int i = 1; i <= n; i++) chk2[i] = false;
        queue <pii> q;
        for(int i = 1; i <= n; i++) {
            if(c[i] == 0) q.em(i, m), chk[i] = true;
        }
        while(!q.empty()) {
            int x = q.front().fi, k = q.front().se;
            q.pop();
            if(k == 1) continue;
            for(auto i : g[x]) {
                if(chk[i]) continue;
                q.em(i, k - 1);
                chk[i] = true;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(c[i] == 1 && !chk[i]) q.em(i, m), chk2[i] = true;
        }
        while(!q.empty()) {
            int x = q.front().fi, k = q.front().se;
            q.pop();
            if(k == 1) continue;
            for(auto i : g[x]) {
                if(chk2[i]) continue;
                q.em(i, k - 1);
                chk2[i] = true;
            }
        }

        bool flag = true;
        for(int i = 1; i <= n; i++) {
            if(!chk2[i] && c[i] == 1) flag = false;
        }
        if(flag) lb = m;
        else ub = m - 1;
    }
    cout << lb << endl;
}