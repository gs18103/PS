#include <cstdio>
#include <queue>
#include <vector>
#define INF 2000000000

using namespace std;
typedef pair<int, int> p;

int d[101010];
bool chk[101010];
vector <p> g[101010];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int s, e, c;
        scanf("%d %d %d", &s, &e, &c);
        g[s].push_back(p(e, c));
        //g[e].push_back(p(s, c));
    }
    int start, en;
    scanf("%d %d", &start, &en);

    for(int i = 1; i <= n; i++)
        d[i] = INF;

    d[start] = 0;
    priority_queue <p> pq;
    pq.push(p(0, start));
    while(!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if(chk[x]) continue;
        chk[x] = true;
        for(int i = 0; i < g[x].size(); i++)
        {
            int y = g[x][i].first;
            if(d[y] > d[x] + g[x][i].second)
            {
                d[y] = d[x] + g[x][i].second;
                pq.push(p(-d[y], y));
            }
        }
    }
    printf("%d", d[en]);
}
