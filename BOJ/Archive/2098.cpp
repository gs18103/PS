#include <bits/stdc++.h>
using namespace std;

int w[17][17];
int dp[1 << 20][17];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &w[i][j]);

	dp[1][0] = 0;

	for(int i = 0; i < (1 << n); i++)
	{
		for(int j = 0; j < n; j++)
		{
			dp[i][j] = 1000000000;
		}
	}

	dp[1][0] = 0;
	for(int i = 0; i < (1 << n); i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(i & (1 << j))
			{
				for(int k = 0; k < n; k++)
				{
					if(k != j && (i & (1 << k)) && w[k][j] != 0)
						dp[i][j] = min(dp[i][j], dp[i-(1<<j)][k] + w[k][j]);
				}
			}
		}
	}

	int ans = 1000000000;
	for(int i = 1; i < n; i++)
	{
		if(w[i][0] != 0)ans = min(ans, dp[(1<<n)-1][i] + w[i][0]);
	}
	printf("%d", ans);
}