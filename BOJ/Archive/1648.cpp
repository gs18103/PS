#include <bits/stdc++.h>
using namespace std;

int dp[200][1<<14];
int n, m;

int f(int num, int s)
{
	if(num == n * m && s == 0) return 1;
	else if(num >= n * m) return 0;
	if(dp[num][s] >= 0) return dp[num][s];

	int ans;
	if(s & 1) ans = f(num+1, (s>>1));
	else
	{
		ans = f(num+1, (s>>1)|(1<<(m-1)));
		if((s & 2) == 0 && num % m != (m - 1))
			ans += f(num+2, (s>>2));
	}
	return dp[num][s] = ans % 9901;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n * m; i++)
		for(int j = 0; j < (1<<m); j++)
			dp[i][j] = -1;
	printf("%d", f(0, 0));
}