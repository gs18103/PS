#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> p;

map <int, int> m;

int a[505050];
int b[505050];
int arr[505050];

long long tree[2005050];

void update(int i, int val, int n)
{
	while(i <= n)
	{
		tree[i] += val;
		i += (i & -i);
	}
}

long long sum(int i)
{
	long long ans = 0;
	while(i > 0)
	{
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		m.insert(p(a[i], i));
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		arr[m[b[i]]] = i;
	}

	for(int i = 1; i <= n; i++) update(i, 1, n);

	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		update(arr[i], -1, n);
		ans += sum(arr[i]);
	}

	printf("%lld", ans);
}