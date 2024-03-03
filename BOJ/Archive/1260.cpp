#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector <int> g[101010];
bool chk[101010];

void dfs(int x) {
    printf("%d ", x);
    chk[x] = true;
    for(int i = 0; i < g[x].size(); i++) {
        if(!chk[g[x][i]]) {
            dfs(g[x][i]);
        }
    }
}

int main() {
    int n, m, V;
    scanf("%d %d %d", &n, &m, &V);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    /*
    a[10101];
    a : a[0]의 주소
    a[i]의 주소 : a + i
    a[1], ..., a[n]
    sort(a+1, a+n+1);
    */
    dfs(V);
    for(int i = 1; i <= n; i++) chk[i] = false;
    printf("\n");
    queue <int> q;
    chk[V] = true;
    q.push(V);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for(int i = 0; i < g[x].size(); i++) {
            if(!chk[g[x][i]]) {
                chk[g[x][i]] = true;
                q.push(g[x][i]);
            }
        }
    }
}