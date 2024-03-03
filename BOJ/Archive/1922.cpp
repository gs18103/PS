#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair <int, int> p;

vector <p> g[101010];
bool chk[101010];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(p(v, w));
        g[v].push_back(p(u, w));
    }

    chk[1] = true;
    int ans = 0;
    priority_queue <p> pq;
    for(int i = 0; i < g[1].size(); i++)
        pq.push(p(-g[1][i].second, g[1][i].first));

    while(!pq.empty())
    {
        p x = pq.top();
        pq.pop();
        if(chk[x.second]) continue;
        chk[x.second] = true;
        ans += -x.first;
        for(int i = 0; i < g[x.second].size(); i++)
            pq.push(p(-g[x.second][i].second, g[x.second][i].first));
    }
    printf("%d", ans);
}
