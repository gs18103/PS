#include <bits/stdc++.h>

using namespace std;

int tree[201010];
int pos[201010];

void update(int i, int diff, int n)
{
	while(i <= n)
	{
		tree[i] += diff;
		i += (i & -i);
	}
}

int sum(int i)
{
	int ans = 0;
	while(i > 0)
	{
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		for(int i = 0; i < 201010; i++)
			tree[i] = 0;

		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = m + 1; i <= n + m; i++)
		{
			update(i, 1, n + m);
			pos[i-m] = i;
		}
		for(int i = m; i >= 1; i--)
		{
			int u;
			scanf("%d", &u);
			printf("%d ", sum(pos[u]) - 1);
			update(pos[u], -1, n + m);
			pos[u] = i;
			update(pos[u], 1, n + m);
		}
		printf("\n");
	}
}