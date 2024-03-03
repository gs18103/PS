#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
typedef pair <int, int> p;

vector <p> g[1010];
priority_queue <p> pq;
priority_queue <int> d[1010];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(p(w, v));
    }

    pq.push(p(0, 1));
    d[1].push(0);
    while(!pq.empty())
    {
        int x = pq.top().second;
        int c = -pq.top().first;
        pq.pop();

        for(int i = 0; i < g[x].size(); i++)
        {
            int t = g[x][i].second;
            if(d[t].size() < k)
            {
                d[t].push(g[x][i].first + c);
                pq.push(p(- g[x][i].first - c, t));
            }
            else if(g[x][i].first + c < d[t].top())
            {
                d[t].pop();
                d[t].push(g[x][i].first + c);
                pq.push(p(- g[x][i].first - c, t));
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(d[i].size() < k) printf("-1\n");
        else printf("%d\n", d[i].top());
    }
}
