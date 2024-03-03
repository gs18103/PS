#include <cstdio>

int d[22][22];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &d[i][j]);

	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i == j) continue;
				if(d[i][j] == d[i][k] + d[k][j] && d[i][k] != 0 && d[k][j] != 0)
					d[i][j] = 0;
				if(d[i][j] > d[i][k] + d[k][j] && d[i][k] != 0 && d[k][j] != 0)
				{
					printf("-1");
					return 0;
				}
			}
		}
	}

	int ans = 0;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ans += d[i][j];
	printf("%d", ans / 2);
}