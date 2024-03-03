#include <bits/stdc++.h>
using namespace std;

int w[17][17];
int dp[1 << 20];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &w[i][j]);

	for(int i = 0; i < (1 << n); i++)
	{
		dp[i] = -1;
	}

	char x[17];
	int t = 0, p;
	scanf("%s %d", x, &p);
	for(int i = 0; i < strlen(x); i++)
		t += (x[i] == 'Y') * (1 << i);

	int ans = -1;
	dp[t] = 0;
	for(int i = 0; i < (1 << n); i++)
	{
		if(dp[i] == -1) continue;
		int cnt = 0, temp = i;
		while(temp > 0)
		{
			if(temp & 1) cnt++;
			temp >>= 1;
		}
		for(int j = 0; j < n; j++)
		{
			if(i & (1 << j))
			{
				for(int k = 0; k < n; k++)
				{
					if((i & (1 << k)) == 0)
					{
						if(dp[i+(1<<k)] == -1 || dp[i+(1<<k)] > dp[i] + w[j][k])
							dp[i+(1<<k)] = dp[i] + w[j][k];
					}
				}
			}
		}
		if(cnt >= p && (ans > dp[i] || ans == -1)) ans = dp[i];
	}

	printf("%d", ans);
}