#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> p;

vector <p> g[505050];

long long d[505050];
long long pre[505050];
bool chk[505050];

priority_queue <p> pq;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		long long u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		g[u].push_back(p(v, w));
		g[v].push_back(p(u, w));
	}

	for(int i = 2; i <= n; i++)
		d[i] = 100000000000000000LL;

	pq.push(p(0, 1));

	long long ans = 0;
	while(!pq.empty())
	{
		long long x = pq.top().second;
		pq.pop();
		if(chk[x])
		{
			continue;
		}
		chk[x] = true;
		for(int i = 0; i < g[x].size(); i++)
		{
			if(d[g[x][i].first] > d[x] + g[x][i].second)
			{
				d[g[x][i].first] = d[x] + g[x][i].second;
				pre[g[x][i].first] = g[x][i].second;
				pq.push(p(-d[g[x][i].first], g[x][i].first));
			}
			else if(d[g[x][i].first] == d[x] + g[x][i].second)
			{
				pre[g[x][i].first] = min(pre[g[x][i].first], g[x][i].second);
			}
		}
	}
	for(int i = 2; i <= n; i++)
	{
		ans += pre[i];
	}
	printf("%lld", ans);
}
