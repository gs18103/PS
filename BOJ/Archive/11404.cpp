#include <cstdio>
#define INF 1000000000

int d[505][505];

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
		}
	}

	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		if(d[u][v] > w)d[u][v] = w;
	}

	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
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
}