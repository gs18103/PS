#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

pair <int, int> arr[101010];
int x[101010];
int seg[101010];

int main()
{
	int n, cnt = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		if(t != arr[cnt].first)
		{
			arr[++cnt].first = t;
			arr[cnt].second = cnt;
		}
	}

	sort(arr+1, arr+cnt+1);

	int d = 1;
	for(int i = 1; i <= cnt; i++)
	{
		x[arr[i].second] = d;
		if(arr[i].first != arr[i+1].first) d++;
	}

	n = cnt;

	if(n == 1)
	{
		printf("1");
		return 0;
	}
	if(x[1] > x[2]) seg[x[1]]++;
	if(x[n] > x[n-1]) seg[x[n]]++;
	for(int i = 2; i < n; i++)
	{
		if(x[i] > x[i-1] && x[i] > x[i+1]) seg[x[i]]++;
		if(x[i] < x[i-1] && x[i] < x[i+1]) seg[x[i]]--;
	}

	int ans = 0, t = 0;
	for(int i = d; i >= 1; i--)
	{
		t += seg[i];
		ans = max(t, ans);
	}
	printf("%d", ans);
}