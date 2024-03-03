#include <stdio.h>

int dp[1001], arr[1001];

int max(int a, int b){return a>b?a:b;}

int main()
{
	int n, ans;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	dp[0] = 1;
	ans = dp[0];
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
			if(arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j]);
		dp[i]++;
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
}