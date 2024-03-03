#include <cstdio>
#include <queue>
#define INF 1000000000
using namespace std;

int d[505][505];
int v[505][505];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j) d[i][j] = 0;
			else d[i][j] = INF;
			v[i][j] = j;
		}
	}

	for(int i = 0; i < m; i++)
	{
		int u, vt, w;
		scanf("%d %d %d", &u, &vt, &w);
		if(d[u][vt] > w)d[u][vt] = w;
	}

	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					v[i][j] = v[i][k];
				}
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++){
			if(d[i][j] != INF)printf("%d ", d[i][j]);
			else printf("0 ");
		}
		printf("\n");
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int cnt = 0, t = i;
			queue <int> q;
			do
			{
				q.push(t);
				t = v[t][j];
				cnt++;
			} while(t != j);
			q.push(j);

			if(d[i][j] == 0 || d[i][j] == INF) printf("0");
			else
			{
				printf("%d ", cnt + 1);
				while(!q.empty())
				{
					printf("%d ", q.front());
					q.pop();
				}
			}
			printf("\n");
		}
	}
}