#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<p, int> x;

int pre[301010];
int cost[301010];
priority_queue <x> pq;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int s, e;
		scanf("%d %d %d", &s, &e, &cost[i]);
		x temp1, temp2;
		temp1.first.first = -s, temp1.first.second = 1, temp1.second = i;
		temp2.first.first = -e, temp2.first.second = 0, temp2.second = i;
		pq.push(temp1);
		pq.push(temp2);
	}

	int ans = 0;
	while(!pq.empty())
	{
		x temp = pq.top();
		if(temp.first.second == 1) pre[temp.second] = ans;
		else ans = max(ans, pre[temp.second] + cost[temp.second]);
		pq.pop();
	}

	printf("%d", ans);
}