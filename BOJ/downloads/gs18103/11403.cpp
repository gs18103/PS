#include <cstdio>

int d[505][505];

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &d[i][j]);
		}


	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(d[i][k] == 1 && d[k][j] == 1) d[i][j] = 1;
			}
		}
	}

	for(int i = 1; i <= n; i++){

		for(int j = 1; j <= n; j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}
}