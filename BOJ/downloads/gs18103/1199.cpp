#include <bits/stdc++.h>
#define eb emplace_back

using namespace std;

int g[1010][1010];
int deg[1010], n;
bool chkE[10101010];
vector <int> ans;

void Euler(int x) {
    vector <int> tmp;
    for(int i = 1; i <= n; i++) {
        if(i == x || g[x][i] == 0) continue;
        while(g[x][i] > 2) {
            tmp.eb(i); g[x][i] -= 2; g[i][x] -= 2;
        }
        g[x][i]--; g[i][x]--;
        Euler(i);
    }
    cout << x << ' ';
    for(int i : tmp) {
        cout << i << ' ' << x << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> g[i][j];
            deg[i] += g[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] % 2 == 1) {
            cout << -1;
            return 0;
        }
    }
    Euler(1);
}