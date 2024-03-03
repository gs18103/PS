#include <bits/stdc++.h>

using namespace std;

int pos[101010];
int tree[401010];
int n;

void update(int k, int diff)
{
	for(int i = k; i <= n; i += (i & -i))
	{
		tree[i] += diff;
	}
}

int sum(int l, int r)
{
	int ans = 0;
	for(int i = r; i > 0; i -= (i & -i))
	{
		ans += tree[i];
	}
	for(int i = l; i > 0; i -= (i & -i))
	{
		ans -= tree[i];
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		pos[t] = i;
		update(i, 1);
	}
	for(int i = 1; i <= n/2; i++)
	{
		printf("%d\n", sum(0, pos[i] - 1));
		update(pos[i], -1);
		printf("%d\n", sum(pos[n+1-i], n));
		update(pos[n+1-i], -1);
	}
	if(n % 2 == 1)
	{
		printf("0\n");
	}
}