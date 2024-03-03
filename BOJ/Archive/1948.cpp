#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair <int, int> p;

vector <p> g[10101];
vector <p> gb[10101];
int chk[10101];
int time[10101];
int indgr[10101];
int r;

void cnt(int k)
{
    if(chk[k] == 1) return;
    chk[k] = 1;
    for(int i = 0; i < gb[k].size(); i++)
    {
        if(gb[k][i].second == time[k] - time[gb[k][i].first])
        {
            r++;
            cnt(gb[k][i].first);
        }
    }
    return;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        g[s].push_back(p(e, w));
        gb[e].push_back(p(s, w));
        indgr[e]++;
    }

    int st, fin;
    scanf("%d %d", &st, &fin);

    queue <int> q;
    q.push(st);
    for(int i = 1; i <= n; i++)
    {
        if(indgr[i] == 0 && i != st)
        {
            chk[i] = 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        int x = q.front();
        q.pop();
        for(int j = 0; j < g[x].size(); j++)
        {
            int c = g[x][j].first;
            int t = g[x][j].second;
            indgr[c]--;
            time[c] = max(time[c], time[x] + t);
            if(indgr[c] == 0) q.push(c);
        }
    }
    printf("%d\n", time[fin]);
    cnt(fin);
    printf("%d", r);
}
