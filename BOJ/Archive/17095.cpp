#include <bits/stdc++.h>

using namespace std;

int arr[101010];
vector <int> v1;
vector <int> v2;

int main()
{
	int n, lb = 10000, ub = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i] > ub) ub = arr[i];
		if(arr[i] < lb) lb = arr[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == lb) v1.push_back(i);
		if(arr[i] == ub) v2.push_back(i);
	}

	int d1 = 0, d2 = 0, ans = 101010;
	while(d1 < v1.size() && d2 < v2.size())
	{
		if(v1[d1] > v2[d2])
		{
			ans = min(ans, v1[d1]-v2[d2]+1);
			d2++;
		}
		else
		{
			ans = min(ans, v2[d2]-v1[d1]+1);
			d1++;
		}
	}
	printf("%d", ans);
}