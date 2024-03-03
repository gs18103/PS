#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector <int> g[32010];
priority_queue <int, vector<int>, greater<int> > pq;
int indgr[32010];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        g[s].push_back(e);
        indgr[e]++;
    }

    for(int i = 1; i <= n; i++)
        if(indgr[i] == 0) pq.push(i);

    for(int i = 0; i < n; i++)
    {
        int x = pq.top();
        pq.pop();
        printf("%d ", x);
        for(int j = 0; j < g[x].size(); j++)
        {
            indgr[g[x][j]]--;
            if(indgr[g[x][j]] == 0) pq.push(g[x][j]);
        }
    }
}
