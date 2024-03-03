#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <int> g[1010];
int arr[1010];
int time[1010];
int indgr[1010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        int t = 0;
        while(1)
        {
            scanf("%d", &t);
            if(t == -1) break;
            g[t].push_back(i);
            indgr[i]++;
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
    for(int i = 1; i <= n; i++) printf("%d\n", time[i]);
}
