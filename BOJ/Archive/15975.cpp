#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p;

vector <long long> v[101010];

p arr[101010];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int x, c;
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	sort(arr, arr + n);

	int m = 0;
	for(int i = 0; i < n; i++)
	{
		v[arr[i].second].push_back((long long)arr[i].first);
		m = max(m, arr[i].second);
	}

	long long ans = 0;
	for(int i = 1; i <= m; i++)
	{
		int x = v[i].size();
		if(x > 1) ans += v[i][1] - v[i][0] + v[i][x-1] - v[i][x-2];
		for(int j = 1; j < x - 1; j++)
		{
			ans += min(v[i][j] - v[i][j-1], v[i][j+1] - v[i][j]);
		}
	}

	printf("%lld", ans);
}