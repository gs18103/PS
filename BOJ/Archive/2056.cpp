#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <int> g[10101];
int arr[10101];
int time[10101];
int indgr[10101];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        scanf("%d", &indgr[i]);
        for(int j = 0; j < indgr[i]; j++)
        {
            int t;
            scanf("%d", &t);
            g[t].push_back(i);
        }
    }

    queue <int> q;
    for(int i = 1; i <= n; i++)
    {
        if(indgr[i] == 0)
        {
            q.push(i);
            time[i] = arr[i];
        }
    }
    for(int i = 0; i < n; i++)
    {
        int x = q.front();
        q.pop();
        for(int j = 0; j < g[x].size(); j++)
        {
            indgr[g[x][j]]--;
            time[g[x][j]] = max(time[g[x][j]], time[x] + arr[g[x][j]]);
            if(indgr[g[x][j]] == 0)
            {
                q.push(g[x][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(ans < time[i]) ans = time[i];
    printf("%d", ans);
}
